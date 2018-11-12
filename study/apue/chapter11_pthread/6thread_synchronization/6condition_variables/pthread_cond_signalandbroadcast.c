#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

#define WAITTHRNUM (8)

static pthread_mutex_t lock[WAITTHRNUM];
static pthread_cond_t cond;

static void *
thr_cond(void *arg)
{
    int locknum = *((int*)arg); 
    int err = 0;

    printf("pthread_self : %ld, locknum: %d\n", (long)pthread_self(), locknum);

    err = pthread_mutex_lock(&lock[0]);
        if (err != 0) printf("pthread_mutex_lock err : %s\n", strerror(err));

    printf("thrednum : %d will enter cond_wait\n", locknum);
    err = pthread_cond_wait(&cond, &lock[0]);
        if (err != 0) printf("pthread_cond_wait err : %s\n", strerror(err));

    pthread_mutex_unlock(&lock[0]); 
    printf("thrnum %d was waked up\n", locknum);

    pthread_exit(PTHREAD_CANCELED);
}

static void *
thr_signal(void *arg)
{
    sleep(1); 
    printf("\nI am signal thread will wake up yours\n");
    int err;

#if 0
    pthread_cond_signal(&cond);
    pthread_cond_signal(&cond);
    pthread_cond_signal(&cond);
    pthread_cond_signal(&cond);
    pthread_cond_signal(&cond);
    pthread_cond_signal(&cond);
    pthread_cond_signal(&cond);
    pthread_cond_signal(&cond);
#else
    err = pthread_cond_broadcast(&cond);
    err = pthread_cond_broadcast(&cond);
    err = pthread_cond_broadcast(&cond);
    err = pthread_cond_broadcast(&cond);
    err = pthread_cond_broadcast(&cond);
    err = pthread_cond_broadcast(&cond);
    err = pthread_cond_broadcast(&cond);
    err = pthread_cond_broadcast(&cond);
    if (err != 0) printf("pthread_cond_broadcast err : %s\n", strerror(err));
#endif

    printf("thr signal will exit\n");
    pthread_exit(PTHREAD_CANCELED);
}

int 
main(int argc, char *argv[])
{
    pthread_t tid_cond[WAITTHRNUM];
    int num_cond[WAITTHRNUM];
    pthread_t tid_signal;
    int i;
    int err;

    err = pthread_cond_init(&cond, NULL);
    if (err != 0)
        printf("pthread_cond_init err : %s\n", strerror(err));

    for (i = 0; i < WAITTHRNUM; i++) {
        err = pthread_mutex_init(&lock[i], NULL);
        if (err != 0)
            printf("pthread_mutex_init err : %s\n", strerror(err));
    }

    for (i = 0; i < WAITTHRNUM; i++) {
        num_cond[i] = i;
        err = pthread_create(&tid_cond[i], NULL, thr_cond, (void*)&num_cond[i]);
        if (err != 0)
            printf("pthread_create err : %s\n", strerror(err));
    }

    err = pthread_create(&tid_signal, NULL, thr_signal, NULL);
    if (err != 0)
        printf("pthread_create err : %s\n", strerror(err));

    pthread_join(tid_signal, NULL);

    return 0;
}
