#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <time.h>

static unsigned int mysleep(unsigned int seconds);

static void
sig_intr(int signo)
{
    if (signo == SIGINT) {
        printf("get SIGINT\n");
    }
}

static void 
sig_alrm(int signo)
{
    if (signo == SIGALRM) {
        printf("get SIGALRM\n");
    }
}

int 
main(int argc, char *argv[])
{
    struct timespec tmb, tme;
    unsigned int elapsed;
    unsigned int slpret; 

    signal(SIGINT, sig_intr);
    signal(SIGALRM, sig_alrm);

    clock_gettime(CLOCK_MONOTONIC, &tmb);

    slpret = mysleep(2);

    clock_gettime(CLOCK_MONOTONIC, &tme);

    elapsed = (tme.tv_sec - tmb.tv_sec)*1000 - (tme.tv_nsec - tmb.tv_nsec)/(1000*1000);

    printf("mysleep ret : %u, elapsed:%ums\n", slpret, elapsed);

    while (1)
        pause();

    return 0;
}

static void
slp_alrmfunc(int signo)
{
    if (signo == SIGALRM) {

    }
}

static unsigned int
mysleep(unsigned int seconds)
{
    void (*sigbef)(int);
    unsigned int rem;

    sigbef = signal(SIGALRM, slp_alrmfunc);
    if (sigbef == SIG_ERR)
        return seconds;

    rem = alarm(0);

    if (rem < seconds) {
        signal(SIGALRM, sigbef);
        return alarm(rem);
    } else {
        alarm(seconds);
        pause();
        signal(SIGALRM, sigbef);
        return alarm(seconds - rem);
    }

    return 0;
}
