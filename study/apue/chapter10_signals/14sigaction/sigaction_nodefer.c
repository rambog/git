#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

static int cnt;

static void
sig_alrm(int signo)
{
    if (signo == SIGALRM) {
        printf("in sigalrm handler\n");
        sleep(1);
        printf("end sigalrm handler\n");
    }
}

static void
sig_intr(int signo)
{
    if (signo == SIGINT) {
        cnt++;
        printf("in sigintr handler:%u\n", cnt);
        sleep(1);
        cnt--;
        printf("end sigintr handler:%u\n", cnt);
    }
}

int
main(int argc, char *argv[])
{
    struct sigaction acintr, acalrm;

    sigemptyset(&acintr.sa_mask);
    acintr.sa_handler = sig_intr;
    acintr.sa_flags = SA_NODEFER;
    if (sigaction(SIGINT, &acintr, NULL) < 0)
        printf("sigaction SIGINT err : %m\n");

    sigemptyset(&acalrm.sa_mask);
    acalrm.sa_handler = sig_alrm;
    acalrm.sa_flags = SA_NODEFER;
    if (sigaction(SIGALRM, &acalrm, NULL) < 0)
        printf("sigaciton SIGALRM err : %m\n");

    for ( ; ; )
        pause();

    return 0;
}
