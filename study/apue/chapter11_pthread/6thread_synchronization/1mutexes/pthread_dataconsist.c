#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

int global1, global2;
pthread_mutex_t mutex;

void *
thr_fn1(void *arg)
{
    for ( ; ; ) {
        pthread_mutex_lock(&mutex);
        global1 = 1;
        global2 = 2;

        if (global1 != 1 || global2 != 2) {
            printf("thread1 data not consist : data1:%d, data2:%d\n", global1, global2);
        }
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void *
thr_fn2(void *arg)
{
    for ( ; ; ) {
        pthread_mutex_lock(&mutex);
        global1 = 3;
        global2 = 4;

        if (global1 != 3 || global2 != 4) {
            printf("thread2 data not consist : data1:%d, data2:%d\n", global1, global2);
        }
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int
main(void)
{
    int err;
    pthread_t tid1, tid2;

    global1 = global2 = 0;
    
    err = pthread_mutex_init(&mutex, NULL);
    if (err != 0) {
        printf("pthread_mutex_init err : %s\n", strerror(err));
        return 0;
    }
    
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0) {
        printf("pthread_create err : %s\n", strerror(err));
        return 0;
    }
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0) {
        printf("pthread_create err : %s\n", strerror(err));
    }

    err = pthread_join(tid1, NULL);
    if (err != 0) {
        printf("pthread_join err : %s\n", strerror(err));
    }
    err = pthread_join(tid2, NULL);
    if (err != 0) {
        printf("pthread_jont err : %s\n", strerror(err));
    }

    return 0;
}
