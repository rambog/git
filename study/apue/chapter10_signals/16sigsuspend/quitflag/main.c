#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

volatile sig_atomic_t quitflag;

static void
sig_int(int signo)
{
    if (signo == SIGINT)
        printf("\ninterrupt\n");
    else if (signo == SIGQUIT)
        quitflag = 1;
}

int
main(void)
{
    sigset_t newmask, oldmask, zeromask;

    if (signal(SIGINT, sig_int) == SIG_ERR) {
        perror("signal SIGINT");
        return 0;
    }

    if (signal(SIGQUIT, sig_int) == SIG_ERR) {
        perror("signal SIGQUIT");
        return 0;
    }

    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);

    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask)< 0) {
        perror("sigpromask block SIGQUIT");
        return 0;
    }

    while (quitflag == 0)
        sigsuspend(&zeromask);

    quitflag = 0;

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        perror("sigpromask setmask oldmask");
        return 0;
    }

    exit(0);
}
