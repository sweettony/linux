#include "testtime.h"
#include <time.h>
#include <sys/time.h>
#include <iostream>

int Get_localtime()
{
    time_t tstramp = time(NULL);
    std::cout << "tstramp = " << tstramp << std::endl;

    struct tm tm_broke;
    localtime_r(&tstramp, &tm_broke);
    std::cout << "tm_gmtoff = " << tm_broke.tm_gmtoff << std::endl;
    std::cout << asctime(&tm_broke) << std::endl;

    struct tm tm_gm_broken;
    gmtime_r(&tstramp, &tm_gm_broken);
    std::cout << "tm_gmtoff = " << tm_gm_broken.tm_gmtoff << std::endl;
    std::cout << asctime(&tm_gm_broken) << std::endl;

    time_t t1 = mktime(&tm_broke);
    std::cout << "===============>" << t1 << std::endl;
    time_t t2 = mktime(&tm_gm_broken);
    std::cout << "===============>" << t2 << std::endl;

    struct timespec ts; //recommemdation
    clock_gettime(CLOCK_REALTIME, &ts);
    std::cout << "timespec = " << ts.tv_sec << "s " << ts.tv_nsec << "ns" << std::endl;

    struct timeval tv;
    gettimeofday(&tv, NULL);
    std::cout << "timeval = " << tv.tv_sec << "s " << tv.tv_usec << "us" << std::endl;

    return 0;
}

//only elapsed time

int Get_elapsed()
{
    struct timespec ts; //recommemdation
    clock_gettime(CLOCK_MONOTONIC, &ts);
    std::cout << "monotonic timespec = " << ts.tv_sec << "s " << ts.tv_nsec << "ns" << std::endl;
    return 0;
}