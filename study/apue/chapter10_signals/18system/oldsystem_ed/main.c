#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

int oldsystem(const char *cmdstring);

static void
sig_int(int signo)
{
    printf("caugth SIGINT\n");
}

static void
sig_chld(int signo)
{
    printf("caught SIGCHLD\n");
}

int
main(void)
{
    if (signal(SIGINT, sig_int) == SIG_ERR)
        return 0;

    if (signal(SIGCHLD, sig_chld) == SIG_ERR)
        return 0;

    if (system("/bin/ed") < 0)
        return 0;

    exit(0);
}
