#!/bin/bash

# Davide Zamboni License

usage_str="usage: $0 <Server IP> <coremask> <nssmask> <Bandwith> <Channel> <Server Port>\n"

IP=$1
CORE=$2
NSS=$3
BW=$4
CHANNEL=$5
PORT=$6

MAKECSIPARAMS="/jffs/makecsiparams"
NEXUTIL="/jffs/nexutil"
PRINTF="/usr/bin/printf"
WL="/usr/sbin/wl"
CLIENT="/jffs/CSI_Client"

if [ "$#" -lt 1 ]; then
    ${PRINTF} "Specify at least Server IP! \n ${usage_str}"
    exit
fi

if [ "$#" -lt 2 ]; then
    NEXUTILV=$(${MAKECSIPARAMS} -c 157/80 -C 0xf -N 1 -m 00:11:22:33:44:66 —b 0x08)
    ${NEXUTIL} -Ieth6 -s500 -b -l34 -v${NEXUTILV}
    ${WL} -i eth6 monitor 1
    ${CLIENT} ${IP} 5672 80
    exit
fi

if [ "$#" -lt 3 ]; then
    ${PRINTF} "Specify at least Core and NSS! \n ${usage_str}"
    exit
fi

if [ "$#" -lt 4 ]; then
    NEXUTILV=$(${MAKECSIPARAMS} -c 157/80 -C ${CORE} -N ${NSS} -m 00:11:22:33:44:66 —b 0x08)
    ${NEXUTIL} -Ieth6 -s500 -b -l34 -v${NEXUTILV}
    ${WL} -i eth6 monitor 1
    ${CLIENT} ${IP} 5672 80
    exit
fi

if [ "$#" -lt 5 ]; then
    NEXUTILV=$(${MAKECSIPARAMS} -c 157/${BW} -C ${CORE} -N ${NSS} -m 00:11:22:33:44:66 —b 0x08)
    ${NEXUTIL} -Ieth6 -s500 -b -l34 -v${NEXUTILV}
    ${WL} -i eth6 monitor 1
    ${CLIENT} ${IP} 5672 ${BW}
    exit
fi

if [ "$#" -lt 6 ]; then
    NEXUTILV=$(${MAKECSIPARAMS} -c ${CHANNEL}/${BW} -C ${CORE} -N ${NSS} -m 00:11:22:33:44:66 —b 0x08)
    ${NEXUTIL} -Ieth6 -s500 -b -l34 -v${NEXUTILV}
    ${WL} -i eth6 monitor 1
    ${CLIENT} ${IP} 5672 ${BW}
    exit
fi

NEXUTILV=$(${MAKECSIPARAMS} -c ${CHANNEL}/${BW} -C ${CORE} -N ${NSS} -m 00:11:22:33:44:66 —b 0x08)
${NEXUTIL} -Ieth6 -s500 -b -l34 -v${NEXUTILV}
${WL} -i eth6 monitor 1
${CLIENT} ${IP} ${PORT} ${BW}
exit

