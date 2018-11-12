#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <pthread.h>

pthread_spinlock_t spinlock;
pthread_mutex_t lock;

static void *
thr_lock(void *arg)
{
    pthread_spin_lock(&spinlock);
    //pthread_mutex_lock(&lock);
}

static void *
thr_unlock(void *arg)
{
    pthread_spin_lock(&spinlock);
    //pthread_mutex_lock(&lock);
}

int
main(void)
{
    pthread_spin_init(&spinlock, PTHREAD_PROCESS_SHARED); 
    pthread_mutex_init(&lock, NULL);

    pthread_t locktid, unlocktid;

    pthread_create(&locktid, NULL, thr_lock, NULL);
    pthread_create(&unlocktid, NULL, thr_unlock, NULL);

    pthread_join(locktid, NULL);
    pthread_join(unlocktid, NULL);

    return 0;
}
