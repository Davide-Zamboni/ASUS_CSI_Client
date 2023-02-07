#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <sstream>
#include <pcap/pcap.h>
using namespace std;

int main(int argc, char **argv)
{
    string source = "244bfebcfd88";
    //string source = "a4d18ce5a360";
    string dst = "ffffffffffff";
    string payload="0800450000280000400040062bbc9d1b92cd1124ce07df2c01bb459376922f575d6250100ffa66ff0000";
    string packetdec = dst + source + payload;

    int length = packetdec.length();
    pcap_t *fp;
    char errbuf[PCAP_ERRBUF_SIZE];
    u_char packet[length];

    /* Check the validity of the command line */
    if (argc != 2)
    {
        printf("usage: %s interface (e.g. 'rpcap://eth0')", argv[0]);
        return 0;
    }

    /* Open the output device */
    if ( (fp= pcap_open_live(argv[1],            // name of the device
                        length,                // portion of the packet to capture (only the first 100 bytes)
                        PCAP_OPENFLAG_PROMISCUOUS,  // promiscuous mode
                        1000,               // read timeout
                        errbuf              // error buffer
    ) ) == NULL)
    {
        fprintf(stderr,"\nUnable to open the adapter. %s is not supported by WinPcap\n", argv[1]);
        return 0;
    }

    int count = 0;
    for (int j = 0; j < length; j=j+2) {
        int x;
        std::stringstream stream;
        stream << std::hex << packetdec.substr(j,2);
        stream >> x;
        packet[count]= x;
        count ++;
    }

    /* Send down the packet */
    while (true) {

        if (pcap_inject(fp, packet, 54 /* size */) == -1) {
            fprintf(stderr, "\nError sending the packet: \n", pcap_geterr(fp));
            return 1;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    return 1;
}
