#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

static void *
thr_fn1(void *arg)
{

}

static void *
thr_fn2(void *arg)
{

}

int
main(void)
{
    pthread_mutex_t lock;
    int err;
    err = pthread_mutex_init(&lock, NULL);
    if (err != 0)
        printf("pthread_mutex_init err : %s\n", strerror(err));

    err = pthread_mutex_unlock(&lock);
    if (err != 0)
        printf("pthread_mutex_unlock err : %s\n", strerror(err));

    err = pthread_mutex_lock(&lock);
    if (err != 0)
        printf("pthread_mutex_lock err : %s\n", strerror(err));

    err = pthread_mutex_destroy(&lock);
    if (err != 0)
        printf("pthread_mutex_destroy err : %s\n", strerror(err));

    printf("enter pause\n");
    while (1) pause();
    return 0;
}
