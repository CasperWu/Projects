#include <pcap.h>
#include <arpa/inet.h>
#include <iostream>

#include "network.h"

using namespace std;

void PcapHandler(u_char *args, const struct pcap_pkthdr *header,
                const u_char *packet);

int main(int argc, char *argv[])
{
    int retval = 0;
    pcap_t *handle;        // Session handle
    char dev[] = "eth0";   // Device to sniff on
    char errbuf[PCAP_ERRBUF_SIZE]; // Error string
    struct bpf_program fp;     // The compiled filter expression
    char filter_exp[] = "tcp"; // The filter expression
    bpf_u_int32 mask;      // The netmask of our sniffing device
    bpf_u_int32 net;       // The IP of our sniffing device

    do {
        if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
            fprintf(stderr, "Can't get netmask for device %s\n", dev);
            net = 0;
            mask = 0;
        }
        handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
        if (handle == NULL) {
            fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
            retval = 2;
            break;
        }
        if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
            fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
            retval = 2;
            break;
        }
        if (pcap_setfilter(handle, &fp) == -1) {
            fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
            retval = 2;
            break;
        }

        int cnt = 1;
        /* Grab a packet */
        pcap_loop(handle, cnt, PcapHandler, NULL);
        /* And close the session */
        pcap_close(handle);
    } while (0);

    return retval;
}

void PcapHandler(u_char *args, const struct pcap_pkthdr *header,
                const u_char *packet)
{
    const struct sniff_ethernet *ethernet; // The ethernet header
    const struct sniff_ip *ip; /* The IP header */
    const struct sniff_tcp *tcp; /* The TCP header */
    const u_char *payload; /* Packet payload */

    u_int size_ip;
    u_int size_tcp;

    do {
        ethernet = (struct sniff_ethernet *)(packet);
        cout << "Ethernet Src: " << ethernet->ether_shost << "\tEthernet Dst: " << ethernet->ether_dhost << endl;

        ip = (struct sniff_ip *)(packet + SIZE_ETHERNET);
        size_ip = IP_HL(ip) * 4;
        if (size_ip < 20) {
            printf("   * Invalid IP header length: %u bytes\n", size_ip);
            break;
        }
        cout << "Src: " << inet_ntoa(ip->ip_src) << "\tDst: " << inet_ntoa(ip->ip_dst) << endl;

        tcp = (struct sniff_tcp*)(packet + SIZE_ETHERNET + size_ip);
        size_tcp = TH_OFF(tcp)*4;
        if (size_tcp < 20) {
            printf("   * Invalid TCP header length: %u bytes\n", size_tcp);
            break;
        }

        if (tcp->th_sum
            != ChecksumTcpUdp(ip->ip_src.s_addr, ip->ip_dst.s_addr,
                    htons(ntohs(ip->ip_len) - size_ip), ip->ip_p, (unsigned char *)tcp)) {
            fprintf(stderr, "TCP checksum validation failed\n");
            break;
        }
        payload = (const u_char *)(packet + SIZE_ETHERNET + size_ip + size_tcp);
    } while (0);
}
