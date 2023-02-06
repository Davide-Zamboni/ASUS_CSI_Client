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
   /* packet[0]=36;
    packet[1]=75;
    packet[2]=254;
    packet[3]=188;
    packet[4]=253;
    packet[5]=136;*/

    packet[0]=36;
    packet[1]=75;
    packet[2]=254;
    packet[3]=189;
    packet[4]=176;
    packet[5]=216;


    /* set mac source to 2:2:2:2:2:2 */
    packet[6]=36;
    packet[7]=75;
    packet[8]=254;
    packet[9]=188;
    packet[10]=253;
    packet[11]=136;


    /*packet[6]=164;
    packet[7]=209;
    packet[8]=140;
    packet[9]=229;
    packet[10]=163;
    packet[11]=96;*/



    /* Fill the rest of the packet */
    //for(i=12;i<100;i++)
    //{
     //   packet[i]=i%256;
   // }
    packet[12]=8;
    packet[13]=00;
    packet[14]=69;
    packet[15]=00;
    packet[16]=00;
    packet[17]=38;
    packet[18]=171;
    packet[19]=73;
    packet[20]=64;
    packet[21]=00;
    packet[22]=255;
    packet[23]=17;
    packet[24]=247;
    packet[25]=00;
    packet[26]=139;
    packet[27]=133;
    packet[28]=217;
    packet[29]=110;
    packet[30]=139;
    packet[31]=85;
    packet[32]=233;
    packet[33]=02;
    packet[34]=153;
    packet[35]=208;
    packet[36]=04;
    packet[37]=63;
    packet[38]=00;
    packet[39]=18;
    packet[40]=114;
    packet[41]=40;
    packet[42]=104;
    packet[43]=101;
    packet[44]=108;
    packet[45]=108;
    packet[46]=111;
    packet[47]=105;
    packet[48]=101;
    packet[49]=108;
    packet[50]=108;
    packet[51]=111;





    /* Send down the packet */
    while (true) {

        if (pcap_inject(fp, packet, 100 /* size */) == -1) {
            fprintf(stderr, "\nError sending the packet: \n", pcap_geterr(fp));
            return 1;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    return 1;
}
