#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void sig_quit(int);

int
main(void)
{
    sigset_t newmask, oldmask, pendmask;

    if (signal(SIGQUIT, sig_quit) == SIG_ERR) {
        printf("signal(SIGQUIT) err : %m\n");
        return 0;
    }

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
        printf("SIG_BLOCK err : %m\n");
        return 0;
    }

    sleep(5);

    if (sigpending(&pendmask) < 0) {
        printf("pending error : %m\n");
        return 0;
    }

    if (sigismember(&pendmask, SIGQUIT))
        printf("\nSIGQUIT pending\n");

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        printf("SIG_SETMASK err : %m\n");
        return 0;
    }

    printf("SIGQUIT unblocked\n");

    sleep(5);

    exit(0);
}

static void
sig_quit(int signo)
{
    printf("caught SIGQUIT\n");
    if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
        printf("can't reset SIGQUIT : %m\n");
}
