#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_t mythread;
pthread_mutex_t mymutex;

void anotherFunc(void)
{
    pthread_mutex_lock(&mymutex);
int i;
    for(i = 0; i < 6; i++)
        printf("anotherFunc\n");

    pthread_mutex_unlock(&mymutex);

    pthread_exit(NULL);
}

void func(void)
{
    pthread_mutex_lock(&mymutex);
int i;
    for(i = 0; i < 6; i++)
        printf("func\n");

    pthread_mutex_unlock(&mymutex);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_mutex_init(&mymutex, NULL);

    pthread_create(&mythread, NULL, func, NULL);
    pthread_create(&mythread, NULL, anotherFunc, NULL);

    pthread_mutex_destroy(&mymutex);

    pthread_exit(NULL);
    return EXIT_SUCCESS;
}
