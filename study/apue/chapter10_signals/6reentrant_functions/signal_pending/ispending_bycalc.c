#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <time.h>


static void 
sig_intr(int signo)
{
    struct timespec tme, tmb;
    if (signo == SIGINT) {
        printf("start SIGINT handler\n");

        clock_gettime(CLOCK_MONOTONIC, &tmb);
        
        unsigned int tick = 0;
        while (tick != ~0)
            tick++;

        clock_gettime(CLOCK_MONOTONIC, &tme);

        unsigned int times = (tme.tv_sec - tmb.tv_sec)*1000 + (tme.tv_nsec - tmb.tv_nsec)/1000000;
        printf("end SIGINT handler ticknum:%# use time :%ums\n", tick, times);
    }
}

static void
sig_quit(int signo)
{
    if (signo == SIGQUIT) {
        printf("start SIGQUIT handler\n");
        printf("end SIGQUIT handler\n");
    }
}

int 
main(int argc, char *argv[])
{
    signal(SIGINT, sig_intr);
    signal(SIGQUIT, sig_quit);

    raise(SIGINT);
    printf("1st trigger sigint\n");
    raise(SIGINT);
    printf("2sc trigger sigint\n");
    raise(SIGINT);
    printf("3tr trigger sigint\n");
    raise(SIGQUIT);
    printf("first trigger sigquit\n");

    printf("all sig trigger\n");

    for ( ; ; ) 
        pause();

    return 0;
}
