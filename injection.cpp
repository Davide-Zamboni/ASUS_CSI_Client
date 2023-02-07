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
    string payload="0800450005dc000040004006b160c0a8015cc0a8010fc125145185f89b0f964883158010080ad06a00000101080a81cc242e4a66656c08346ccc0364ba0922bb069e0f6d3b698360abb49c8a33c0c498a735bc17b06482ddf8a03a286f3cc9f9c588cf6334a33fa51712388c2dd7978ae7a7c96ff0e658e11234deb743ad1ddbf79f6008e14938c3ad6c0df4b8df82cb4694627a9be574acaff6aa54291a8f474a7a2e9b0667365a42a5d1e0f7e0c7a40d65a03cc7c279189d19d9135c78795d03ec0a05e0f4778a0cd3e47cb0eda8ab1941aeda0048b57986f5b291e0d7307e5cdb60081e802a67bdca760c02cf9849f716434f11b89fb87b08aff4adc27d4725f509ba21a97ffdb6ce708f3b85c6d4ce8d24aa6610f7cdf1fd61c1a2d267ae440de5d1d398ede40afc0cdbad4938f88e2f9224a2b3a7d9162b93702a025e04bb2061bed7ce48b7b8c610de1d179880fbf6601e0fbfb83fdb7f3b78eb9dbc3e532fcb66634bb8ab06da521833e3900cdc99daf174cd773d518d953e2559ec94ce072b41af00c5c70b125dfb01153118cce917824529c8491ab45044591edf911e037903953785885608261ec040bb349c1bbe174bc801883baf9ff765860e59f5ec7b8a2037bd6ea3f1c91386cf8701b63f209dde7794f5f38dc5bc53e4b179a683bc94339efebd981a659f17439d069b971247f838db8f3970dc4f323632b0bfca25e6132adf4d16b2dc7326b05b4211c979a2790934f3715924f57c77be24fcef3641f3835f1a028db75e995402784da907f8ef9c4cde6fa5713dd325adf333ec776a6f8f061d2e5217aac0edc428f3a63502234839598a93b9909caca2d122a56fd09a9db6ca5c808b897f10a2015cbb13178e895edf51c1fddd4c6b335fa4e1d77d52741ea1b7c3a981b7eca10bd248c9c77489d422f77ad53df167f94c572a3432b419248c5d00930aade4f25a0f9457279349ae1605206e2dc65a1325cb6926d6857a11fff164efaf207a0d04f21b31c46bedf550e0e0f69b7e46fb3ea4f4afcfe48658edeaff47f45d01e282b5975fbc6b6347226a6a244bda133c83519c0a204e005049144dcd675c6ed9225058e48f352c2d41850b8bef006a503a59fa2adb0353996a0cc105de456588aa251e22b09076018e1895fa595ed29d8cd9231a974bd8912232042373331ed47d74d73c9b978d09cf268e0522189fe255b76754bf0923051f3a01f9ad1570127b51fed4db7399be0c825323c1b691d03f8db4e6b8890e7f3d95e9c4d81aaa590bcd604227f768e13599e7f1d58c58aba900f6caf36c5c2cb1ede3cff194525b3f75e549bdbccc7e74b0d04ba7e9b85ecd0d57f0d7601abfb0c119a626d74eee4ecb3a37a9fff337f8230a69decf77727b1241f75e4263ecbb4710efa1e076269bbeff031d742e2bf19b44292fe0dad9cffc5485067f0a19104da6ee9c99826bc678d31d0bf12e9d71d5684281a2b74fb91800d5f715076861dd937a2dbe52bbe35fb9da5b484852290091b0e74df8da7a94bbb464999b3510a14155e71d2d7e54c72630a52ae958e8702183736b8bc7169bea659757161ec30806349c6c46ca9396bc2684576e9b6e199a8f5a7f3cd85a6834ed917987f4b67bd2b7ee584cb3d0d210ee05989f396e56d1844e7eca05fdda71b81446f7f9bc0313312cb92794e897d81ee6f5a1a79d6621e55bf2108afeedda3f6189bf5e5c2d4792d8d8ba3739f8ccd67de2f991981d98807b2494d9022e9b14c28e5901f3b236bca46c412b271c8629beff61802e8237cd3ed96ecf0033c7cd895fbfcc2585d43c14b2594148fa607b7d4ebb152d27a311f2c68e3d41459ceae4dc48c0e0c5f476f857c4762e370059c81bf804191b0c7c91e21cd3e52c1a2dee16d92c8c535ed3f950815e0920b54878abb0e9735970ab6aa8e4a885b9fa01ad4f6c4ff0e2b17ba93d4c95b67f5b92b57200f9154e9cca44d8ee519756bd45a410c7f516f9f2232bf1f3491f8c4c886118aa4d61f23fcf14fdeb91f5ee598c2acddb8c2bd015cb713e45df3462af82e930e9e85a0617ef6d49da86be536dff5fe530aabbd410c2c49eb961fb986269c2ef19a646605da0ae2e00";
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

        if (pcap_inject(fp, packet, length /* size */) == -1) {
            fprintf(stderr, "\nError sending the packet: \n", pcap_geterr(fp));
            return 1;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    return 1;
}
