#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <thread>

#include <pcap/pcap.h>


int main(int argc, char **argv)
{
    pcap_t *fp;
    char errbuf[PCAP_ERRBUF_SIZE];
    u_char packet[100];
    int i;

    /* Check the validity of the command line */
    if (argc != 2)
    {
        printf("usage: %s interface (e.g. 'rpcap://eth0')", argv[0]);
        return 0;
    }

    /* Open the output device */
    if ( (fp= pcap_open_live(argv[1],            // name of the device
                        100,                // portion of the packet to capture (only the first 100 bytes)
                        PCAP_OPENFLAG_PROMISCUOUS,  // promiscuous mode
                        1000,               // read timeout
                        errbuf              // error buffer
    ) ) == NULL)
    {
        fprintf(stderr,"\nUnable to open the adapter. %s is not supported by WinPcap\n", argv[1]);
        return 0;
    }

    /* Supposing to be on ethernet, set mac destination to 1:1:1:1:1:1 */
    packet[0]=255;
    packet[1]=255;
    packet[2]=255;
    packet[3]=255;
    packet[4]=255;
    packet[5]=255;

    /* set mac source to 2:2:2:2:2:2 */
    packet[6]=2;
    packet[7]=2;
    packet[8]=2;
    packet[9]=2;
    packet[10]=2;
    packet[11]=2;

    /* Fill the rest of the packet */
    for(i=12;i<100;i++)
    {
        packet[i]=i%256;
    }

    /* Send down the packet */
    while (true) {
        if (pcap_sendpacket(fp, packet, 100 /* size */) != 0) {
            fprintf(stderr, "\nError sending the packet: \n", pcap_geterr(fp));
            return 1;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    return 1;
}
