#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

static void
sig_intr(int signo)
{

}

int
main(int argc, char *argv[])
{
    signal(SIGINT, sig_intr);

    sigset_t sigmask;
    sigemptyset(&sigmask);

    sigaddset(&sigmask, SIGINT);

    if (sigprocmask(SIG_BLOCK, &sigmask, NULL) < 0) {
        perror("sigprocmask block SIGINT");
        return 0;
    }

    sleep(5);

#if 0
    if (sigprocmask(SIG_UNBLOCK, &sigmask, NULL) < 0) {
        perror("sigprocmaks unblock SIGINT");
        return 0;
    }

    pause();
#else
    sigdelset(&sigmask, SIGINT);
    sigsuspend(&sigmask);
#endif

    return 0;
}
