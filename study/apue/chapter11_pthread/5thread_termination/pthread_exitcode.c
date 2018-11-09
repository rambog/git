#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

void *
thr_fn1(void *arg)
{
    printf("thread 1 returning\n");

    return ((void*)1);
}

void *
thr_fn2(void *arg)
{
    printf("thread 2 exiting\n");

    pthread_exit((void*)2);
}

void *
thr_fn3(void *arg)
{
    printf("thread 3 cancel\n");

    while (1) 
        sleep(1);
}

int
main(void)
{
    int err;
    pthread_t tid1, tid2, tid3;
    void *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0) {
        printf("pthread create err : %s\n", strerror(err));
        return 0;
    }
    err = pthread_join(tid1, &tret);
    if (err != 0) {
        printf("pthread join err : %s\n", strerror(err));
    }
    printf("thread1 retcode : %p\n", tret);
    
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0) {
        printf("pthread create err : %s\n", strerror(err));
        return 0;
    }
    err = pthread_join(tid2, &tret);
    if (err != 0) {
        printf("pthread join err : %s\n", strerror(err));
    }
    printf("thread2 exitcode : %p\n", tret);

    err = pthread_create(&tid3, NULL, thr_fn3, NULL);
    if (err != 0) {
        printf("pthread create err : %s\n", strerror(err));
        return 0;
    }
    sleep(1);
    pthread_cancel(tid3);
    err = pthread_join(tid3, &tret);
    if (err != 0) {
        printf("pthread join err : %s\n", strerror(err));
    }
    printf("thread3 cancelcode : %p\n", tret);

    return 0;
}
