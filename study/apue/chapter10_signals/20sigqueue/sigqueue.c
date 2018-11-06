#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void
sig_intr(int signo)
{
    printf("in sigintr handler\n");



    printf("exit sigintr handler\n");
}

static void
sig_intrac(int signo, struct siginfo_t *info, void *txt)
{
    printf("in sigintraction handler\n");

    sleep(1);

    printf("exit sigintraction handler\n");
}

int
main(int argc, char *argv[])
{
    struct sigaction acintr;

    acintr.sa_sigaction = sig_intrac; 
    sigemptyset(&acintr.sa_mask);
    acintr.sa_flags = 0;
    acintr.sa_flags |= SA_SIGINFO;
    if (sigaction(SIGINT, &acintr, NULL) < 0) {
        perror("sigaction SIGINT err");
        return 0;
    }

    union sigval val;
    sigqueue(getpid(), SIGINT, val);
    sigqueue(getpid(), SIGINT, val);
    sigqueue(getpid(), SIGINT, val);
    printf("sigqueue finish\n");

    while (1)
        pause();

    return 0;
}
