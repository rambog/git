#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#define PRINTSIG(signo) printf("%s get sig[%d] : %s\n", __FUNCTION__, signo, #signo)

static void 
sig_func1(int signo)
{
    unsigned int tick = 0;
    switch (signo) {
        case SIGINT :
            while (tick != ~0)
                tick++;
            PRINTSIG(SIGINT);
            break;
        case SIGQUIT :
            PRINTSIG(SIGQUIT);
            exit(0);
            break;
        case SIGTSTP :
            PRINTSIG(SIGTSTP);
            break;
        default :
            return;
    }
}

static void 
sig_func2(int signo)
{
    unsigned int tick = 0;
    switch (signo) {
        case SIGINT :
            while (tick != ~0)
                tick++;
            PRINTSIG(SIGINT);
            break;
        case SIGQUIT :
            PRINTSIG(SIGQUIT);
            exit(0);
            break;
        case SIGTSTP :
            PRINTSIG(SIGTSTP);
            break;
        default :
            return;
    }
}

static void *
thr_func(void *arg)
{
    for ( ; ; ) {
        //signal(SIGINT, sig_func1);
        //kill(getpid(), SIGINT);
        //signal(SIGINT, sig_func2);
        //kill(getpid(), SIGINT);
        usleep(200*1000);
        printf("once trigger!\n");
    }
    
    pthread_exit(0);
}

int
main(int argc, char *argv[])
{
    signal(SIGQUIT, sig_func1);
    signal(SIGTSTP, sig_func1);
    signal(SIGINT, sig_func1);

    pthread_t pid;
    pthread_create(&pid, NULL, thr_func, NULL);

#if 0
    for ( ; ; ) {
        //signal(SIGINT, sig_func1);
        //kill(getpid(), SIGINT);
        //signal(SIGINT, sig_func2);
        //kill(getpid(), SIGINT);
        usleep(200*1000);
        printf("once trigger!\n");
    }
#endif
    for ( ; ; )
        pause();

    return 0;
}
