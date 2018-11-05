#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <signal.h>
#include <unistd.h>
#include <errno.h>

static void
sig_intr(int signo)
{
    if (signo == SIGINT) {
        printf("cautch SIGINT\n");
        sleep(1);
        printf("SIGINT deal finish\n");
        exit(0);
    }
}

int
main(int argc, char *argv[])
{
    sigset_t sigmask, sigpend;

    if (signal(SIGINT, sig_intr) == SIG_ERR) {
        printf("signal SIGINT err : %m\n");
        return 0;
    }

    if (sigprocmask(SIG_BLOCK, NULL, &sigmask) < 0) 
        printf("get sigmask err : %m\n");

    sigpending(&sigpend);
    if (sigismember(&sigpend, SIGINT))
        printf("SIGINT is pend\n");

    if (sigaddset(&sigmask, SIGINT) < 0)
        printf("sigmask add SIGINT err : %m\n");

    if (sigprocmask(SIG_BLOCK, &sigmask, NULL) < 0)
        printf("set sigmask(add SIGINT) err : %m\n");

    raise(SIGINT);
    printf("raise SIGINT end\n");

    sleep(1);

    if (sigprocmask(SIG_UNBLOCK, &sigmask, NULL) < 0)
        printf("set sigmask(del SIGINT) err : %m\n");

    for ( ; ; )
        pause();

    return 0;
}
