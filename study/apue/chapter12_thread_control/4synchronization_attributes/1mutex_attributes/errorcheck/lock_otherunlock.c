#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t errorlock;

void *
thr_fn1(void *arg)
{
    int err;
    pthread_detach(pthread_self());

    err = pthread_mutex_lock(&errorlock);
    if (err != 0)
        printf("pthread_mutex_lock err : %s\n", strerror(err));
    
    while(1) pause();
}

void *
thr_fn2(void *arg)
{
    int err;
    pthread_detach(pthread_self());

    sleep(1);
    err = pthread_mutex_unlock(&errorlock);
    if (err != 0)
        printf("pthread_mutex_unlock err: %s\n", strerror(err));
    
    while(1) pause();
}

int 
main(void)
{
    pthread_mutexattr_t mutexattr;
    
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_ERRORCHECK);
    pthread_mutex_init(&errorlock, &mutexattr);
    pthread_mutexattr_destroy(&mutexattr);

    pthread_t tid;
    int err;

    err = pthread_create(&tid, NULL, thr_fn1, NULL);
    err = pthread_create(&tid, NULL, thr_fn2, NULL);

    while (1) pause();
    return 0;
}
