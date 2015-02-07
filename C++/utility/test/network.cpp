
#include <cassert>
#include <iostream>

#include "network.h"

using namespace std;

int main()
{
    /* Here a IP header captured by tcpdumpa.
     */
    const unsigned char ip[] = {0x45, 0x00, 0x00, 0x28, 0xef, 0xee, 0x40, 0x00, 0x40, 0x06, 0x37, 0x3e, 0xc0, 0xa8, 0x96, 0x83, 0xc0, 0x1e, 0xfc, 0x58};
    const sniff_ip *ipHeader = (const sniff_ip *)ip;

    unsigned short csum = ChecksumIp(ip, sizeof(ip));
    if (ipHeader->ip_sum != csum) {
        cout << "Checksum validation failed\n";
    } else {
        cout << "Checksum validation successful\n";
    }
}
