#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <unistd.h>
#include <pthread.h>

void *
thr_tmp(void *arg)
{
    //printf("i am :%lu\n", pthread_self());
    while (1) pause();

    pthread_exit(PTHREAD_CANCELED);
}

int
main(void)
{
    pthread_t tid_tmp;
    unsigned int max = sysconf(_SC_THREAD_THREADS_MAX);
    int i = 0;
    int err;

    printf("max : %u\n", max);
    for (i = 0; i < max; i++) {
        err = pthread_create(&tid_tmp, NULL, thr_tmp, NULL);
        if (err != 0) {
            printf("pthread_create err : %s cur idx:%u\n", strerror(err), i);
            break;
        }
    }

    printf("enter pause\n");
    while (1) pause();
    printf("main exit\n");
    return 0;
}
