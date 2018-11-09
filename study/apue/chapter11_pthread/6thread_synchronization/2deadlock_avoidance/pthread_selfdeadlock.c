#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;

static void *
thr_fn(void *arg)
{
    int err;
    printf("enter thread\n");

    err = pthread_mutex_lock(&lock);
    if (err != 0)
        printf("pthread_mutex_lock err : %s\n", strerror(err));

    err = pthread_mutex_lock(&lock);
    if (err != 0)
        printf("pthread_mutex_lock err : %s\n", strerror(err));

    printf("exit thread\n");
}

int
main(void)
{
    pthread_t tid;
    int err;

    err = pthread_mutex_init(&lock, NULL);
    if (err != 0) {
        printf("pthread mutex init err : %s\n", strerror(err));
        return 0;
    }

    err = pthread_create(&tid, NULL, thr_fn, NULL);
    if (err != 0) {
        printf("pthread create err : %s\n", strerror(err));
        return 0;
    }

    err = pthread_join(tid, NULL);
    if (err != 0) {
        printf("pthread joing err : %s\n", strerror(err));
        return 0;
    }

    return 0;
}
