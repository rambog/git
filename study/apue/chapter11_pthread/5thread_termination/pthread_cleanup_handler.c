#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

void
cleanup_handler1(void *arg)
{
    printf("cleanup handler1\n");
}

void
cleanup_handler2(void *arg)
{
    printf("cleanup handler2\n");
}

void *
thr_fn1(void *arg)
{
    pthread_cleanup_push(cleanup_handler1, NULL);
    pthread_cleanup_push(cleanup_handler1, NULL);
    
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);

    return NULL;
}

void *
thr_fn2(void *arg)
{
    pthread_cleanup_push(cleanup_handler1, NULL);
    pthread_cleanup_push(cleanup_handler2, NULL);

    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);

    pthread_exit(PTHREAD_CANCELED);
}

void *
thr_fn3(void *arg)
{
    pthread_cleanup_push(cleanup_handler1, NULL);
    pthread_cleanup_push(cleanup_handler2, NULL);

    while (1) {
        pthread_testcancel();
        sleep(1);
    }

    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);

    return NULL;
}

int
main(void)
{
    pthread_t tid1, tid2, tid3;
    int err;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0) {
        printf("pthread_create : %s\n", strerror(err));
        return 0;
    }
    err = pthread_join(tid1, NULL);
    printf("thread1 join\n");
    
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0) {
        printf("pthread_create : %s\n", strerror(err));
        return 0;
    }
    err = pthread_join(tid2, NULL);
    printf("thread2 join\n");

    err = pthread_create(&tid3, NULL, thr_fn3, NULL);
    if (err != 0) {
        printf("pthread_create : %s\n", strerror(err));
        return 0;
    }
    sleep(1);
    pthread_cancel(tid3);
    err = pthread_join(tid3, NULL);
    printf("thread3 join\n");

    return 0;
}
