
#include <cassert>
#include <iostream>

#include <gtest/gtest.h>

#include "network.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "Running main() from gtest_main.cc\n";  
    testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();  
}


TEST(ChecksumIp, RandomCheck)
{
    /* Here a IP header captured by tcpdumpa.
     */
    const unsigned char ip[] = {0x45, 0x00, 0x00, 0x28, 0xef, 0xee, 0x40, 0x00, 0x40, 0x06, 0x37, 0x3e, 0xc0, 0xa8, 0x96, 0x83, 0xc0, 0x1e, 0xfc, 0x58};
    const sniff_ip *ipHeader = (const sniff_ip *)ip;

    const unsigned short csum = ChecksumIp(ip, sizeof(ip));

    EXPECT_EQ(ipHeader->ip_sum, csum);
}
