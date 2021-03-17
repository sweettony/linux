#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <string>

sem_t g_mutex;
int fd = -1;

std::string str1 = "-------------------------func1\n";
std::string str2 = "-------------------------func2\n";
void* func1(void* parg)
{
    int count = 2000;
    while (count--)
    {
        sem_wait(&g_mutex);
        write(fd, str1.c_str(), str1.size());
        sem_post(&g_mutex);

    }
    
    return NULL;
}

void* func2(void* parg)
{
    int count = 2000;
    while (count--)
    {
        sem_wait(&g_mutex);
        write(fd, str2.c_str(), str2.size());
        sem_post(&g_mutex);
    }
    return NULL;
}
int main()
{
    fd = ::open("./print.txt", O_CREAT|O_RDWR|O_TRUNC);
    sem_init(&g_mutex, 0, 1);
    pthread_t t1, t2;
    pthread_create(&t2, NULL, &func2, NULL);
    pthread_create(&t1, NULL, &func1, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&g_mutex);
    ::close(fd);
    return 0;
}