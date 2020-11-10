#include <stdlib.h>  
#include <stdio.h>  
#include <stddef.h>  
#include <sys/socket.h>  
#include <sys/un.h>  
#include <errno.h>  
#include <string.h>  
#include <unistd.h>  


int main()
{

    int sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        printf("sock failed\n");
        return 0;
    }
    
    struct sockaddr_un name;
    name.sun_family = AF_UNIX;
    strcpy(name.sun_path, "./tuya.sock");
//     unlink("./tuya.sock");
    // if (bind(sock, (struct sockaddr *) &name, sizeof(struct sockaddr_un))) {
    //     printf("bind failed\n");
    //     return 0;
    // }
    char buff[1024];
    int ret = 1; 
   while ( ( ret= sendto(sock, buff, ret, 0, (struct sockaddr*)&name, sizeof(name))) != 0)
   {
       scanf("%s", buff);
       ret = strlen(buff);
       printf("write= %d\n", ret);
   } 
    //int ret = write(sock, "123", 3);

    return 0;
}