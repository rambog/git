#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>

static void
sig_alrm(int signo)
{
    if (signo == SIGALRM) {
        printf("get signo SIGALRM\n");
        sleep(3);
        printf("finish SIGALRM\n");
    }
}

int
main(int argc, char *argv[])
{
    sigset_t sigset;

    if (-1 == sigprocmask(SIG_BLOCK, NULL, &sigset)) {
        printf("sigprocmask err : %m\n");
    }

    sigdelset(&sigset, SIGSTOP);

    if (-1 == sigprocmask(SIG_BLOCK, &sigset, NULL)) {
        printf("sigprocmask block SIGKILL err : %m\n");
    }

    signal(SIGALRM, sig_alrm); 

    alarm(3);
    alarm(3);
    alarm(3);

    printf("send alrm sig\n");

    while (1) pause();

    return 0;
}
