#include <iostream>
#include <stdio.h>

int main()
{
    char* p = (char*)3;
    try
    {
        delete  p;
        int b = 3/0;
    }
    catch(...)
    {
        printf("------------------------------------------- hahhhahahahhahhahah\n");
    }
    int a, b;
    printf("------------------------------------------- hahhhahahahhahhahah\n");
    return 0;
}