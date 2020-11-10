#include <iostream>
#include "unixsock.h"
#include <stdio.h>

const static char* path  = "./unix.sock";

int main()
{
    do
    {
        int sock = unix_dgram_socket();
        if(sock < 0) break;

        char buff[(1024 << 10)];
        int size = 0;
        

        if( unix_dgram_server_bind(sock, path) < 0)
            break;

        while(buff[0] != '0')
        {
            scanf("%s", buff);
            size = unix_dgram_server_read(sock, buff, (1024 << 10));
            if(size > 0)
            {
                printf("size = %d\n", size);
            }
        }
        unlink(path);
    } while (0);
    return 0;
}