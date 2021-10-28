#!/bin/env python3

import sys, getopt
import struct

IMG_OFFSET = 0x4000
RO_MAX_OFFSET = 0x330

def extract(in_file, out_file):
    size = -1
    f = open(in_file, 'rb')

    # get image size
    f.seek(IMG_OFFSET + RO_MAX_OFFSET) # move to the size of the image
    size = struct.unpack('<I', f.read(4))[0] # read 4 bytes of the image size
    size -= 0x40000 + IMG_OFFSET # remove base address
    if (size < 0) or (size >= 0x40000):
        print("Wrong image size.")
        exit()

    # dump image
    f.seek(IMG_OFFSET)
    rw_a = f.read(size + 1)
    f.close()

    out = open(out_file, 'wb')
    out.write(rw_a)
    out.close()

def main(argv):
    inputfile = ''
    outputfile = ''
    
    try:
        opts, args = getopt.getopt(argv,"h",[])
    except getopt.GetoptError:
        print('Parsing issue')
        sys.exit(2)

    if len (args) < 2:
        print('extract-rw_a.py <inputfile.ec> <rw_a.bin>')
        sys.exit(2)


    for opt, arg in opts:
        if opt == '-h':
            print('extract-rw_a.py <inputfile.ec> <rw_a.bin>')
            sys.exit()

    extract(args[0], args[1])


if __name__ == "__main__":
    main(sys.argv[1:])

