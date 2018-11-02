#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

static void sig_func(int);
static void* thr_func(void *);

static pthread_mutex_t mt;

int
main(int argc, char *argv[])
{
    pthread_t tid[2];
    char tmp[2][12];
    int ret;

    pthread_mutex_init(&mt, NULL);

    signal(SIGQUIT, sig_func);
    signal(SIGINT, sig_func);
    signal(SIGTSTP, sig_func);


    int i = 0;
    for (i = 0; i < sizeof(tid)/sizeof(pthread_t); i++) {
        sprintf(tmp[i], "%d", i);
        if ((ret = pthread_create(tid+i, NULL, thr_func, (void*)tmp[i]))!= 0)
            perror("creat thread err");
    }

#if 0
    for (i = 0; i < sizeof(tid)/sizeof(pthread_t); i++) {
        if ((ret = pthread_join(tid[1], NULL)) != 0)
            printf("pthread join err : %s\n", strerror(ret));
    }
#endif

    while (-1 == pause())
        printf("main pthread:%lld awak by signal\n", pthread_self());

    exit(0);
}

static void
sig_func(int signo)
{
    struct timespec tmb, tme;

    if (signo == SIGQUIT)
        exit(0);

    if (signo == SIGINT) {
        pthread_mutex_lock(&mt);
#if 0
        clock_gettime(CLOCK_MONOTONIC, &tmb);
        
        unsigned int tick = 0x00;
        while (tick != ~0)
            tick++;
            
        clock_gettime(CLOCK_MONOTONIC, &tme);
        unsigned int times = (tme.tv_sec - tmb.tv_sec)*1000 + (tme.tv_nsec - tmb.tv_nsec)/1000000;
#endif
        usleep(200*1000);
        pthread_mutex_unlock(&mt);
        //printf("tid:%lld SIGINT sleep(%d) end\n", pthread_self(), times);
    }
}

static void*
thr_func(void *arg)
{
    pthread_detach(pthread_self());

    for ( ; ; ) {
        pthread_mutex_lock(&mt);
        printf("i am thread:%lld ord:%s\n", (long long)pthread_self(), (char*)arg);
        usleep(100*1000);
        pthread_mutex_unlock(&mt);
        usleep(100*1000);
    }
}
