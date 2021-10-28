import csv
import sys
from struct import *
from enum import Enum
from ctypes import *
import logging
import argparse

NOS_STATE = None
NosCmd = None
curr_status = None

# load parser native library
libparser = CDLL("libparser.so")

# call libparser with proper arguments
def parse_nos_cmd():

    global NosCmd, NOS_STATE, curr_status
    if (NosCmd == None):
        logging.error("Unasign cmd")
        exit()

    response = create_string_buffer(NosCmd.response)
    request = create_string_buffer(NosCmd.request)
    
    libparser.parser(c_uint(NosCmd.app_id), c_uint(NosCmd.cmd), request, sizeof(request), response, sizeof(response))

    NOS_STATE = None
    NosCmd = None

# CSV clomunm
# Timestamp, transfer, data
timestamp = 'timestamp'
transfer = 'transfer'
data = 'data'

mosi_name   = "MOSI transfer"
miso_name   = "MISO transfer"

# State machine for nos commands
class NosState(Enum):
    CMD_INIT = 0
    CMD_DONE = 1
    RCV_INIT = 2
    RCV_DONE = 3

# Nos command class for application layer
class NosCommand:
    def __init__(self, app_id):
        self.app_id = app_id
        self.cmd = None
        self.request = bytes()
        self.response = bytes()

# SPICommand class for transport layer
class SPICommand:
    def __init__(self, packet_id, app_id, param, is_transport, is_data, is_read, more_to_come):
        self.packet_id = packet_id
        self.app_id = app_id
        self.param = param
        self.is_transport = is_transport
        self.is_data = is_data
        self.is_read = is_read
        self.more_to_come = more_to_come
        self.request = None
        self.response = None
        self.action = None
        self.miso_awake = False
        self.miso_ready = False

# transport_status 
# returned by miso after GET_STATUS
class Transport_status:
    def __init__(self, s, rl, l=0, v=0, f=0, c=0, rc=0):
        self.status = s # app status
        self.reply_len= rl
        self.length = l
        self.version = v
        self.flag = f
        self.crc = c
        self.reply_crc = rc

# Mask for app status
APP_STATUS_IDLE = 0x00000000
APP_STATUS_DONE = 0x80000000
class App_Status(Enum):
    APP_SUCCESS = 0
    APP_ERROR_BOGUS_ARGS = 1
    APP_ERROR_INTERNAL = 2
    APP_ERROR_TOO_MUCH = 3
    APP_ERROR_IO = 4
    APP_ERROR_RPC = 5
    APP_ERROR_CHECKSUM = 6
    APP_ERROR_BUSY = 7
    APP_ERROR_TIMEOUT = 8
    APP_SPECIFIC_ERROR = 0x20
    APP_LINE_NUMBER_BASE = 0x70000000


# Get transport_status from bytes
def parse_status(data, version):

    ts = unpack('<IH', data[0:6])
    if version == 1:
        ts += unpack('<HHHHH', data[6:16])
    return Transport_status(*ts)

# Container for SPI data extracted from the CVS file
class SPIPacket:
    def __init__(self, packet_id):
        self.packet_id = packet_id
        self.mosi = bytearray()
        self.miso = bytearray()

    def set_miso(self, miso):
        self.miso = miso

    def set_mosi(self, mosi):
        self.mosi = mosi

# Type of possible command (only two used)
class RequestType(Enum):
    GET_STATUS = 0
    CLEAR_STATUS = 1

# Parse data from mosi
def parse_mosi(pid, mosi):
    global NOS_STATE, NosCmd, curr_status
    if len(mosi) < 4:
        logging.error("Error: wrong mosi len " + str(len(mosi)))
        return None

    # parse mosi command

    cmd = mosi[0:4]
    is_transport = ((cmd[0] & 0x40) != 0)
    is_data = (cmd[0] & 0x20 != 0)
    is_read = (cmd[0] & 0x80 != 0)
    more_to_come = ((cmd[0] & 0x10) != 0)
    data = mosi[5:]
    app_id = int(cmd[1])
    param = int.from_bytes(cmd[2:], byteorder='big', signed=False)

    c =  SPICommand(pid, int(cmd[1]), int.from_bytes(cmd[2:], byteorder='big', signed=False), is_transport, is_data, is_read, more_to_come)
    logging.debug("AppId: " + str(int(cmd[1])) + " param=" + str(int.from_bytes(cmd[2:], byteorder='big', signed=False)) + " data=" + str(is_data) + " transport=" + str(is_transport) + " read=" + str(is_read) + " more=" + str(more_to_come))

    # check for get_status
    if (c.is_transport and c.is_read and not c.is_data and c.param == 0):
        c.action = RequestType.GET_STATUS
        logging.debug("     <-> Get Status")
    elif (c.is_transport and not c.is_read and not c.is_data and c.param == 0):
        c.action = RequestType.CLEAR_STATUS
        logging.debug("     <-> Clear Status")
    elif NOS_STATE == None or NosState == NosState.RCV_DONE:
        NosCmd = NosCommand(c.app_id)
        NOS_STATE = NosState.CMD_INIT
        NosCmd.request += data
        logging.debug("     CMD_INIT")
    elif NOS_STATE == NosState.CMD_INIT:
        if (not more_to_come):
            logging.debug("     CMD_DONE")
            NosCmd.cmd = param
            NOS_STATE = NosState.CMD_DONE
        NosCmd.request += data
    elif NOS_STATE == NosState.CMD_DONE:
        if curr_status != None and curr_status.reply_len != 0 and is_read:
            logging.debug("     CMD_RCV_INIT")
            NOS_STATE = NosState.RCV_INIT
        else:
            logging.debug("     CMD_ None")
            NOS_STATE = None
    elif NOS_STATE == NosState.RCV_INIT:
        if (not more_to_come):
            NosState.RCV_DONE
            logging.debug("     RCV_DONE")

    return c

# Parse data from miso
def parse_miso(cmd, miso): 
    global NOS_STATE, NosCmd, curr_status
    cmd.miso_awake = (miso[0:4] == 0xdfdfdfde.to_bytes(4, 'big'))
    cmd.miso_ready = (miso[4] == 1)

    logging.debug("     is_awake=" + str(cmd.miso_awake) + " is_ready=" + str(cmd.miso_ready))
    if (cmd.miso_awake and cmd.miso_ready):
        if (cmd.action == RequestType.GET_STATUS):
            if (len(miso[5:]) < 16):
                logging.debug("         Status V0")
                curr_status = parse_status(miso[5:], 0)
            else:
                curr_status = parse_status(miso[5:], 1)
                logging.debug("         status=" + str(curr_status.status & APP_STATUS_DONE != 0))
                logging.debug("         length=" + str(curr_status.length))
                logging.debug("         version=" + str(curr_status.version))
                logging.debug("         reply_len=" + str(curr_status.reply_len))
        # TODO check app status (done, error, etc)
        elif cmd.action == RequestType.CLEAR_STATUS:
            # TODO
            if NOS_STATE == NosState.RCV_INIT or NOS_STATE == NosState.CMD_DONE:
                logging.debug(" -> Cmd end " + str(NosCmd.app_id) + "  " + str(NosCmd.cmd))
                parse_nos_cmd()
        elif (NOS_STATE == NosState.RCV_INIT or NOS_STATE == NosState.RCV_DONE):
            NosCmd.response += miso[5:]

def parse_bytes(s):
    return bytes.fromhex(s)

# Call the different parsing function for an SPI packet
def parse_packet(curr):
    cmd = parse_mosi(curr.packet_id, curr.mosi)
    if (cmd is None):
        logging.warning("Ignore packet " + str(curr.packet_id))
        return

    parse_miso(cmd, curr.miso)
    is_awake = (curr.miso[0:4] == 0xdfdfdfde.to_bytes(4, 'big'))
    logging.debug("      Packet " + str(curr.packet_id) + "\n\t\t -> mosi(" + curr.mosi.hex() + "),\n\t\t -> miso(" + curr.miso.hex() + ")")

def main():
    csv.field_size_limit(sys.maxsize) # may crash
    packet_id = -1
    curr = None

    parser = argparse.ArgumentParser(description='Toto')
    parser.add_argument('csvfile', metavar='csvfile', type=str,
                    help='CVS file containing traces')
    parser.add_argument('--debug', '-d', action="store_true",
                    help='show debug strings')

    args = parser.parse_args()
    if args.debug:
        logging.basicConfig(level=logging.DEBUG)

    last_t = 0
    with open(args.csvfile, newline='') as csvfile:
        reader = csv.DictReader(csvfile, delimiter=',', quoting=csv.QUOTE_NONE)
        for row in reader:
            #Sample,Time,Decoder,Ann Row,Ann Class,Value,
            try:
                if "transfer" not in row['Ann Class']: # Only take into account Transfer rows
                    logging.debug("Not a transfert row. Skipping.")
                    continue

                t = int(row['Sample'])
            except:
                logging.error("Error: wrong timestamp: '"+ row['Sample'] + "'")
                exit()

            if (len(row['Value']) == 0):
                logging.warning("Skipping empty row")
                continue
 
            if last_t != t:
                if (curr != None):
                    parse_packet(curr)

                packet_id += 1
                last_t = t
                curr = SPIPacket(packet_id)

            if(row['Ann Class'] == miso_name):
                curr.set_miso(parse_bytes(row['Value']))
            elif (row['Ann Class'] == mosi_name):
                curr.set_mosi(parse_bytes(row['Value']))
            else:
                logging.error("error: wrong transfer type: '" + row['Ann Class'] + "'")



if __name__ == "__main__":
    # execute only if run as a script
    main()
