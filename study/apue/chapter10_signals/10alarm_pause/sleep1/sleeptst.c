#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <time.h>

static void
sig_alrm(int signo)
{
    if (signo == SIGALRM) {
        printf("get SIGALRM\n");    
    }
}

static void
sig_intr(int signo)
{
    if (signo == SIGINT) {
        printf("get SIGINT\n"); 
    }
}

int
main(int argc, char *argv[])
{
    struct timespec tmb, tme;
    unsigned int sleepret;

    signal(SIGALRM, sig_alrm);
    signal(SIGINT, sig_intr);

    pid_t pid;
    pid = fork();
    if (pid < 0) {
        return 0;
    } else if (pid == 0) {
        pid = getppid();
        usleep(1500*1000);
        //kill(pid, SIGINT);
        return 0;
    }

    alarm(1);
    usleep(300*1000);

    clock_gettime(CLOCK_MONOTONIC, &tmb);

    sleepret = sleep(3);

    clock_gettime(CLOCK_MONOTONIC, &tme);

    unsigned int elapsed; 
    elapsed = (tme.tv_sec - tmb.tv_sec)*1000 + (tme.tv_nsec - tmb.tv_nsec)/(1000*1000);

    printf("sleep time :%ums, sleep retv :%u\n", elapsed, sleepret);

    while (1) pause();

    return 0;
}
