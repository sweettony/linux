#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    DIR* dp;
    dp = opendir(".");
    if(dp == NULL)
    {
        printf("---------------------error dp\n");
    }
    struct dirent entry;
    struct dirent* presult;
    readdir_r(dp, &entry, &presult);
    while(presult != NULL)
    {
        if(S_ISREG(presult->d_type))
            printf("name = %s\n", presult->d_name);
        readdir_r(dp, &entry, &presult);
    }
    return 0;
}