#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock1;
pthread_mutex_t lock2;

static void *
thr_fn1(void *arg)
{
    int err;
    printf("enter thread\n");

    sleep(1);
    for ( ; ; ) {
        err = pthread_mutex_lock(&lock1);
        if (err != 0)
            printf("pthread_mutex_lock err : %s\n", strerror(err));

        err = pthread_mutex_lock(&lock2);
        if (err != 0)
            printf("pthread_mutex_lock err : %s\n", strerror(err));

        printf("thread1 lock test\n");
    }

    printf("exit thread\n");
}

static void *
thr_fn2(void *arg)
{
    int err;
    printf("enter thread\n");

    sleep(1);
    for ( ; ; ) {
        err = pthread_mutex_lock(&lock2);
        if (err != 0)
            printf("pthread_mutex_lock err : %s\n", strerror(err));

        err = pthread_mutex_lock(&lock1);
        if (err != 0)
            printf("pthread_mutex_lock err : %s\n", strerror(err));

        printf("thread2 lock test\n");
    }

    printf("exit thread\n");
}

int
main(void)
{
    pthread_t tid1, tid2;
    int err;

    err = pthread_mutex_init(&lock1, NULL);
    if (err != 0) {
        printf("pthread mutex init err : %s\n", strerror(err));
        return 0;
    }
    err = pthread_mutex_init(&lock2, NULL);
    if (err != 0) {
        printf("pthread mutex init err : %s\n", strerror(err));
        return 0;
    }

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0) {
        printf("pthread create err : %s\n", strerror(err));
        return 0;
    }
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0) {
        printf("pthread create err : %s\n", strerror(err));
        return 0;
    }

    err = pthread_join(tid1, NULL);
    if (err != 0) {
        printf("pthread joing err : %s\n", strerror(err));
        return 0;
    }
    err = pthread_join(tid2, NULL);
    if (err != 0) {
        printf("pthread joing err : %s\n", strerror(err));
        return 0;
    }

    return 0;
}
