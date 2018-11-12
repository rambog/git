#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define MAXTHR (4)
static pthread_mutex_t lock[MAXTHR];
static pthread_cond_t cond;

static void
unlock_alllock(int num)
{
    int i = 0;
    for (i = 0; i < num; i++)
        pthread_mutex_unlock(&lock[i]);
}

static void *
thr_wait(void *arg)
{
    int thrnum = *((int*)arg);
    printf("I am thread : %ld thrnum : %d\n", (long)pthread_self(), thrnum);
    pthread_mutex_lock(&lock[thrnum]);
    pthread_cond_wait(&cond, &lock[thrnum]);
    printf("after wait %ld will exit\n", (long)pthread_self());
    //pthread_mutex_unlock(&lock[thrnum]);

    pthread_exit(PTHREAD_CANCELED);
}

static void *
thr_sig(void *arg)
{
    sleep(1);

#if 0
    pthread_cond_signal(&cond);
    pthread_cond_signal(&cond);
    pthread_cond_signal(&cond);
    pthread_cond_signal(&cond);
#else
    unlock_alllock(MAXTHR);
    pthread_cond_broadcast(&cond);
    pthread_cond_broadcast(&cond);
    pthread_cond_broadcast(&cond);
    pthread_cond_broadcast(&cond);
#endif
    printf("thread signal will exit\n");
    pthread_exit(PTHREAD_CANCELED);
}

int
main(void)
{
    pthread_t tid_wait[MAXTHR];
    pthread_t tid_sig;
    int thr_num[MAXTHR];
    int err;
    int i;

    pthread_cond_init(&cond, NULL);

    for (i = 0; i < MAXTHR; i++) {
        thr_num[i] = i;
        pthread_mutex_init(&lock[i], NULL);
        pthread_create(&tid_wait[i], NULL, thr_wait, (void*)(&thr_num[i]));
    }

    pthread_create(&tid_sig, NULL, thr_sig, NULL);

    for (i = 0; i < MAXTHR; i++)
        pthread_join(tid_wait[i], NULL);
    pthread_join(tid_sig, NULL);

    return 0;
}
