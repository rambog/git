#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

void *
thr_fn(void *arg)
{
    int err;

    printf("enter thread1 \n");

    err = pthread_join(pthread_self(), NULL);
    if (err != 0) {
        printf("pthread_join self err : %s\n", strerror(err));
    }

    printf("thread1 exit\n");

    pthread_exit(PTHREAD_CANCELED);
}

int
main(void)
{
    pthread_t tid;
    int err;

    err = pthread_create(&tid, NULL, thr_fn, NULL);
    if (err != 0) {
        printf("pthread_create err :%s\n", strerror(err));
        return 0;
    }

    while (1)
        pause();

    return 0;
}
