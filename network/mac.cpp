#include <iostream>
#include <sstream>
#include <string>
#include <string.h>



#include <sys/ioctl.h>
#include <sys/ioctl.h>
#include <net/if.h> 
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>

int mac(const std::string name, )
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
        return -3;
    ss << (unsigned int)stifr.ifr_ifru.ifru_hwaddr.sa_data[0] << "."\
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