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

int
main(int argc, char *argv[])
{
    pthread_t tid[2];
    char tmp[2][12];
    int ret;

    signal(SIGQUIT, sig_func);
    signal(SIGINT, sig_func);
    signal(SIGTSTP, sig_func);

    int i = 0;
    for (i = 0; i < sizeof(tid)/sizeof(pthread_t); i++) {
        sprintf(tmp[i], "%d", i);
        if ((ret = pthread_create(tid+i, NULL, thr_func, (void*)tmp[i]))!= 0)
            perror("creat thread err");
    }

    for (i = 0; i < sizeof(tid)/sizeof(pthread_t); i++) {
        if ((ret = pthread_join(tid[1], NULL)) != 0)
            printf("pthread join err : %s\n", strerror(ret));
    }

    exit(0);
}

static void
sig_func(int signo)
{
    struct timespec tme, tmb;

    if (signo == SIGQUIT)
        exit(0);

    if (signo == SIGINT) {
        clock_gettime(CLOCK_MONOTONIC, &tmb);
#if 0
        unsigned int tick = 0x00;
        while (tick != ~0)
            tick++;
#else
        sleep(3);
#endif

        clock_gettime(CLOCK_MONOTONIC, &tme);
        unsigned int times = (tme.tv_sec - tmb.tv_sec)*1000 + (tme.tv_nsec - tmb.tv_nsec)/1000000;

        printf("SIGINT sleep(%ums) end\n", times);
    }
}

static void*
thr_func(void *arg)
{
    for ( ; ; ) {
        printf("i am thread:%lld ord:%s\n", (long long)pthread_self(), (char*)arg);
        sleep(1);
    }
}
