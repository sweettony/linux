#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include<string.h>

int main()
{
    int fd = open("./seek.file", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    if(fd < 0)
    {
        printf("open error\n");
    }

    off_t off = lseek(fd, 3, SEEK_SET);
    if(off < 0)
    {
        printf("lseek error\n");
    }

    const char*  hello = "i am tanghan.ye";
    size_t len = strlen(hello);
    int ret = write(fd, hello, len);
    if(ret != len)
    {
        printf("write error\n");
    }

    off = lseek(fd, 0, SEEK_SET);
    if(off < 0)
    {
        printf("lseek error\n");
    }

    unsigned char buff[1024] = { 0 };
    ret = read(fd, buff, 1024);
    printf("ret = %d\n", ret);
    int i = 0;
    for(i = 0; i < ret; i++)
        printf("%c", buff[i]);
    
    printf("=======%c======\n", '\0');
    
    // const char*  hi = "hi,";
    // len = strlen(hi);

    // ret = write(fd, hi, len);
    // if(ret != len)
    // {
    //     printf("write error\n");
    // }
    return 0;
}