#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>

static void sig_func(int);
static void* thr_func(void *);

int
main(int argc, char *argv[])
{
    pthread_t tid[8];
    char tmp[8][12];
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
    if (signo == SIGQUIT)
        exit(0);

    if (signo == SIGINT) {
        unsigned int tick = 0x00;
        while (tick != ~0)
            tick++;
        printf("SIGINT sleep end\n");
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
