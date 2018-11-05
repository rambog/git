#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>

static void
sig_intr(int signo)
{
    if (signo == SIGINT)
    {

    }
}

int
main(int argc, char *argv[])
{
    if (signal(SIGINT, sig_intr) == SIG_ERR) {
        printf("signal SIGINT err : %m\n");
        return 0;
    }

    sigset_t sigmask, oldsigmask;

    sigemptyset(&sigmask);
    sigaddset(&sigmask, SIGINT);

    if (sigprocmask(SIG_BLOCK, &sigmask, &oldsigmask) < 0) {
        printf("sigprocmask add SIGINT err : %m\n");
        return 0;
    }

    sigset_t pending;
    for ( ; ; ) {
        sigpending(&pending); 
        if (sigismember(&pending, SIGINT))
            printf("SIGINT is pending\n");
        else
            printf("SIGINT is not pending\n");

        usleep(400*1000);
    }

    return 0;
}
