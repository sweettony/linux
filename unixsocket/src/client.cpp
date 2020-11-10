#include <iostream>
#include <stdio.h>
#include "unixsock.h"

const static char* path  = "./unix.sock";

int main()
{
    do
    {
        int sock = unix_dgram_socket();
        if(sock < 0) break;
        char buff[1024 * 100];
        int size = 0;
        
        struct sockaddr_un unix_addr = { 0 };
        unix_addr.sun_family = AF_UNIX;
        size = strlen(path);
        memcpy(unix_addr.sun_path, path, size);
        size = 0;
        while(buff[0] != '0')
        {
            scanf("%s", buff);
            // printf("size = %d, buff = %s\n", size, buff);
            size = unix_dgram_server_send(sock, buff, 1024 * 100, &unix_addr);
            //if(size < 0) break;
            printf("size = %d\n", size);
            
        } 
    } while (0);
    
    return 0;
}