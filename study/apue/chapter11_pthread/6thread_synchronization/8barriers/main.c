#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THR (8)

static pthread_barrier_t barrier;

static void *
thr_bar(void *arg)
{
    int err;
    err = pthread_barrier_wait(&barrier);
    if (err == PTHREAD_BARRIER_SERIAL_THREAD)
        printf("last end in pthread:%ld\n", (long)pthread_self());
}

int
main(void)
{
    pthread_t tid[MAX_THR];
    int i;
    int err;

    pthread_barrier_init(&barrier, NULL, MAX_THR+1);

    for (i = 0; i < MAX_THR; i++)
        pthread_create(&tid[i], NULL, thr_bar, NULL);

    sleep(1);
    err = pthread_barrier_wait(&barrier); 
    if (err == PTHREAD_BARRIER_SERIAL_THREAD)
        printf("last of barrier in main!\n");

    for (i = 0; i < MAX_THR; i++)
        pthread_join(tid[i], NULL);

    return 0;
}
