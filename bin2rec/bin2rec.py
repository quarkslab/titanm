#!/bin/env python

import hashlib
import sys, getopt
import os



def formatBlock(block, count, addr):
    output = bytearray()
    temp = bytes()
    temp += count.to_bytes(4, byteorder='little')
    temp += addr.to_bytes(4, byteorder='little')
    temp += block

    hash_header = hashlib.sha256(temp).digest()
    if b'\x00' in hash_header:
        print("zero byte in hash header")

    output += bytearray(hash_header)
    output += bytearray(temp)
    hash_footer = hashlib.sha256(bytes(output)).digest()
    hash2 = hash_footer.replace(b'\x00', b'\x01') # replace zero byte
    output += bytearray(hash2)

    return bytes(output)

def bin2rec(inputfile, outputfile, start_count, start_address):
    stat = os.stat(inputfile)
    rest = stat.st_size % 0x3d8

    fin = open(inputfile,'rb')
    fout = open(outputfile, 'wb')
    count = start_count
    addr = start_address
    fblock = bytes()

    while True:
        block = fin.read(0x3d8) # reading blocks of 0x3d8
        if not block or len(block) != 0x3d8:
            print('Reached EOF')
            break;

        fblock = formatBlock(block, count, addr)
        fout.write(fblock)
        count += 1
        addr += 0x3d8

    if rest != 0:
        print("Add padding (" + str(rest)+ ")")
        block += bytes([0xff for i in range(0x3d8 - rest)])
        count += 0x80000000 # last block index is always bigger
        fblock = formatBlock(block, count, addr)
        fout.write(fblock)

    fin.close()
    fout.close()

def getData(block):
    count = block[0x20:0x24]
    addr = block[0x24:0x28]
    data = block[0x28:0x400]
    return data

def rec2bin(inputfile, outputfile):

    fin = open(inputfile,'rb')
    fout = open(outputfile, 'wb')
    count = 0
    data = bytes()

    while True:
        block = fin.read(0x420)
        if not block:
            break;
        # TODO verify hashes
        data = getData(block)
        fout.write(data)

    fin.close()
    fout.close()

def main(argv):
    inputfile = ''
    outputfile = ''
    start_count = 0
    reverse = False
    start_address = 0x4000

    try:
        opts, args = getopt.getopt(argv,"hcar",[])
    except getopt.GetoptError:
        print('Parsing issue')
        sys.exit(2)

    if len (args) < 2:
        print('bin2rec.py [-c <start count>] [-a <start_address>] [-r] <inputfile> <outputfile>')
        sys.exit(2)


    for opt, arg in opts:
        if opt == '-h':
            print('bin2rec.py [-c <start count>] [-a <start address>] <inputfile> <outputfile>')
            sys.exit()
        elif opt == '-c':
            start_count = int(arg, base=16)
        elif opt == '-a':
            address = int(arg, base=16)
        elif opt == '-r':
            reverse = True

    inputfile = args[0]
    outputfile = args[1]
    if not reverse:
        bin2rec(inputfile, outputfile, start_count, start_address)
    else:
        rec2bin(inputfile, outputfile)

if __name__ == "__main__":
    main(sys.argv[1:])

