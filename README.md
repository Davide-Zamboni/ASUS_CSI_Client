# ASUS_CSI_Client
This project allows you to extract channel state information (CSI) of the Broadcom bcm4366c0 Wi-Fi Chip used in Asus RT-AC86U and send them threw a RabbitMQ server.
## Requrements
- [Nexmon CSI extractor](https://github.com/seemoo-lab/nexmon_csi) installed on the router.
- aarch64 toolchain for cross compilation.
## Installation guide
1. Clone the repository: `git clone https://github.com/Davide-Zamboni/ASUS_CSI_Client.git`.
2. Change the directory of the RabbitMQ cross-compiled library in lines 13, 14, and 15 to the directory of where you cloned the repository (`/CC libraries/rabbitmq-c-0.11.0`).

3. Cross-compile the code specifying the cross-compiled libraries directory: 
```
aarch64-linux-gnu-g++ main.cpp -o CSI_Client -lpcap -L/.../libpcap -static -lrabbitmq -I/.../rabbitmq-c-0.11.0/librabbitmq
```
4. Copy the binary file in the router:
```
scp CSI_Client admin@<address of your rt-ac86u>:/jffs/CSI_Client
ssh admin@<address of your rt-ac86u> "/bin/chmod +x /jffs/CSI_Client"
```

## Usage Example
Here follows an example for using the program on a 5 GHz Wi-Fi (eth6). The configuration used enables the collection on channel 36 with 80 MHz bandwith.
```
ssh admin@<address of your rt-ac86u>
cd /jffs
./makecsiparams -c 36/80 -C 4 -N 1 -m 12:13:31:AC:1F:F9 -b 0x88
./nexutil -Ieth6 -s500 -b -l34 -v<string genereted with makecsiparams>
/usr/sbin/wl -i eth6 monitor 1
./CSI_Client <address of your RabbitMQ Server> <Port> <Bandwith> <verbose/noverbose>
```

Alternatively you can use the simple script provided in the utils folder:
1. Copy the script for using the tool:
```
cd /utils
scp start_sniffing.sh admin@<address of your rt-ac86u>:/jffs/start_sniffing.sh
ssh admin@<address of your rt-ac86u> "/bin/chmod +x /jffs/start_sniffing.sh"
```
2. Run the script:
```
cd /jffs
./start_sniffing.sh <Server IP> <verbose/noverbose> <coremask> <nssmask> <Bandwith> <Channel> <Server Port>
```
By default the configuration of the sctipt is set to `noverbose`, `core = 0xf`, `nss = 1`, `bandith = 80`, `channel = 157`, `server port = 5672`. You must specify at least a Server IP.

