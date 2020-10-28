#include "testtime.h"
#include <time.h>
#include <sys/time.h>
#include <iostream>

int Get_localtime()
{
    time_t tstramp = time(NULL);
    std::cout << "tstramp = " << tstramp << std::endl;

    struct timespec ts; //recommemdation
    clock_gettime(CLOCK_REALTIME, &ts);
    std::cout << "timespec = " << ts.tv_sec << "s " << ts.tv_nsec << "ns" << std::endl;

    
    struct timeval tv;
    gettimeofday(&tv, NULL);
    std::cout << "timeval = " << tv.tv_sec << "s " << tv.tv_usec << "us" << std::endl;

    return 0;
}