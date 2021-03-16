#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <iomanip>


#include <sys/ioctl.h>
#include <sys/ioctl.h>
#include <net/if.h> 
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>

    // std::stringstream ss;
    // #define MACFORMAT std::setw(2) << std::setfill('0') << std::setbase(16)
    // for(int i = 0; i < 5; i++)
    //     ss  << MACFORMAT << (stifr.ifr_ifru.ifru_hwaddr.sa_data[i] & 0xFF)<< ":";
    // ss  << MACFORMAT << (stifr.ifr_ifru.ifru_hwaddr.sa_data[5] & 0xFF);
    // #undef MACFORMAT
    // std::cout << "addr = " << ss.str() << std::endl;
typedef struct
{
	unsigned char  c[6];
} MACADDR; //IP addr

int mac(const std::string name, MACADDR& mac)
{
    if(name.size() == 0)
        return -1;
    
    struct ifreq stifr;

    int size = (IFNAMSIZ - 1) > name.size() ? name.size() : (IFNAMSIZ - 1);
    memcpy(&stifr.ifr_ifrn.ifrn_name, name.c_str(), size);
    stifr.ifr_ifrn.ifrn_name[size] = '\0';

    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd < 0) 
        return -2;

    if (ioctl(fd, SIOCGIFHWADDR, &stifr) == -1)
    {
        close(fd);
        return -3;
    }
    memcpy(&mac, stifr.ifr_ifru.ifru_hwaddr, sizeof(struct sockaddr));
    close(fd);
    return 0;
}
int main()
{
    std::string addr;
    mac("enp0s3", addr);
    std::cout << "addr = " << addr << std::endl;
    std::stringstream ss;
    char a = 90;
    ss << a;
    std::cout << "addr = " << ss.str() << std::endl;
    return 0;
}