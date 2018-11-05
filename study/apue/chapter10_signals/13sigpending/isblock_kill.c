#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void
sig_intr(int signo)
{
    if (signo == SIGINT) {
        printf("beg SIGINT in sigcautch\n");

        sleep(1);

        printf("end SIGINT in sigcautch\n\n");
    }
}

static void
sig_alrm(int signo)
{
    if (signo == SIGALRM) {
        printf("beg SIGALRM in sigcautch\n");

        sleep(1);

        printf("end SIGALRM in sigcautch\n\n");
    }
}

int
main(int argc, char *argv[])
{
    if (signal(SIGINT, sig_intr) == SIG_ERR) {
        printf("signal SIGINT err : %m\n");
        return 0;
    }

    if (signal(SIGALRM, sig_alrm) == SIG_ERR) {
        printf("signal SIGALRM err : %m\n");
        return 0;
    }

    int i = 0;
    for (i = 0; i < 5; i++) {
        printf("raise SIGINT %d\n", i);
        raise(SIGINT);
    }

    sigset_t setmask, oldmask;
    sigemptyset(&setmask);
    sigaddset(&setmask, SIGALRM);
    sigprocmask(SIG_BLOCK, &setmask, &oldmask);
    for (i = 0; i < 5; i++) {
        printf("raise SIGALRM %d\n", i);
        raise(SIGALRM);
    }
    sigprocmask(SIG_SETMASK, &oldmask, NULL);

    for (i = 0; i < 5; i++) {
        printf("alarm %d\n", i);
        alarm(1);
    }

    while (1) pause();

    return 0;
}
