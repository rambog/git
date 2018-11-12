#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>
#include <errno.h>

static pthread_mutex_t lock;
static pthread_cond_t cond;

void *
thr_wait(void *arg)
{
    int err;
    printf("enter thread:%ld\n", (long)pthread_self());

    err = pthread_mutex_lock(&lock);
    if (err != 0) printf("pthread_mutex_lock : %s\n", strerror(err));

    err = pthread_cond_wait(&cond, &lock);
    if (err != 0) printf("pthread_cond_wait : %s\n", strerror(err));

    printf("exit thread:%ld\n", (long)pthread_self());
    pthread_exit(PTHREAD_CANCELED);
}

int
main(void)
{
    pthread_t tid_wait;
    int err;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    err = pthread_cond_signal(&cond);
    if (err != 0) printf("pthread_cond_broadcast err : %s\n", strerror(err));

    pthread_create(&tid_wait, NULL, thr_wait, NULL);

    sleep(1);
    //pthread_cond_broadcast(&cond);

    while (1) pause;
    exit(0);
}
