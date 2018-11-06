#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void
sig_abrt(int signo)
{
    printf("in sig_abrt handler\n");
}

int
main(int argc, char *argv[])
{
    //signal(SIGABRT, sig_abrt);
    //signal(SIGABRT, SIG_IGN);
    sigset_t newmask;

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGABRT);
    if (sigprocmask(SIG_BLOCK, &newmask, NULL) < 0) {
        perror("sigblock err");
    }

    abort();
    //raise(SIGABRT);

    printf("exit main\n");

    return 0;
}
