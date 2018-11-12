#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t reclock;

static void *
thr_fn1(void *arg)
{
    int err;

    err = pthread_mutex_lock(&reclock);
    if (err != 0) printf("pthread_mutex_lock err : %s\n", strerror(err));

    err = pthread_mutex_lock(&reclock);
    if (err != 0) printf("pthread_mutex_lock again err : %s\n", strerror(err));
    printf("relock twice\n");

    sleep(1);

    printf("first release relock\n");
    err = pthread_mutex_unlock(&reclock);
    if (err != 0) printf("pthread_mutex_unlock again err : %s\n", strerror(err));

    sleep(1);

    printf("release relock again\n");
    err = pthread_mutex_unlock(&reclock);
    if (err != 0) printf("pthread_mutex_unlock again err : %s\n", strerror(err));
}

static void *
thr_fn2(void *arg)
{
    int err;
    usleep(100*1000);

    err = pthread_mutex_lock(&reclock);
    if (err != 0) printf("thr2 pthread_mutex_lock err : %s\n", strerror(err));
    printf("thr2 get the relock\n");
}

int
main(void)
{
    pthread_mutexattr_t lockattr;

    pthread_mutexattr_init(&lockattr);
    pthread_mutexattr_settype(&lockattr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&reclock, &lockattr);
    pthread_mutexattr_destroy(&lockattr);

    pthread_t tid;

    pthread_create(&tid, NULL, thr_fn1, NULL);
    pthread_create(&tid, NULL, thr_fn2, NULL);

    while (1) pause();
    return 0;
}
