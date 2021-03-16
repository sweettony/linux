#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;
int fd = -1;

std::string str1 = "-------------------------func1\n";
std::string str2 = "-------------------------func2\n";
void* func1(void* parg)
{
    while (1)
    {
        pthread_mutex_lock(&g_mutex);
        write(fd, str1.c_str(), str1.size());
        pthread_mutex_unlock(&g_mutex);
        pthread_yield();
    }
    
    return NULL;
}

void* func2(void* parg)
{
    while (1)
    {
        pthread_mutex_lock(&g_mutex);
        write(fd, str2.c_str(), str2.size());
        pthread_mutex_unlock(&g_mutex);
        pthread_yield();
    }

    return NULL;
}
int main()
{
    fd = ::open("./print.txt", O_CREAT|O_RDWR|O_TRUNC);

    pthread_t t1, t2;
    pthread_create(&t2, NULL, &func2, NULL);
    pthread_create(&t1, NULL, &func1, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    ::close(fd);
    return 0;
}