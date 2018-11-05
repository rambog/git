#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void
sig_alrm(int signo)
{
    if (signo == SIGALRM)
    {
        printf("in SIGALRM handler\n");
    }
}

int
main(int argc, char *argv[])
{
    struct sigaction sigac;

    memset(&sigac, 0x00, sizeof(struct sigaction));
    sigemptyset(&sigac.sa_mask);
    sigac.sa_handler = sig_alrm;
    //sigac.sa_flags = SA_INTERRUPT;
    sigac.sa_flags = SA_RESTART;
    //sigac.sa_sigaction = NULL;
    if (sigaction(SIGALRM, &sigac, NULL) < 0) {
        printf("sigaction SIGALRM err : %m\n");
    }

    alarm(1);

    char buf[128];
    ssize_t n;

    if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
        printf("read err : %m\n");

    return 0;
}
