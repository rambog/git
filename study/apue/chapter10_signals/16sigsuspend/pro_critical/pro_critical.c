#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <signal.h>
#include <errno.h>
#include <unistd.h>

void pr_mask(const char *str);

static void sig_int(int);

int
main(void)
{
    sigset_t newmask, oldmask, waitmask;

    pr_mask("program start: ");

    if (signal(SIGINT, sig_int) == SIG_ERR) {
        perror("signal SIGINT");
        return 0;
    }
    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
        perror("sigprocmask newmask");
        return 0;
    }

    pr_mask("in critical region: ");

    if (sigsuspend(&waitmask) != -1) {
        perror("sigsuspend error");
    }

    pr_mask("after return from sigsuspend: ");

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        perror("sigprocmask oldmask");
        return 0;
    }

    pr_mask("program exit: ");

    exit(0);
}

static void
sig_int(int signo)
{
    pr_mask("\nin sig_int: ");
}
