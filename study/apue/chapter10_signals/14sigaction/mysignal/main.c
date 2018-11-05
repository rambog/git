#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

void (*mysignal(int ,void (*)(int)))(int);

static void
sig_intr(int signo)
{
    if (signo == SIGINT) {
        printf("cautch sigint\n");
    }
}

int
main(int argc, char *argv[])
{
    if (mysignal(SIGINT, sig_intr) == SIG_ERR) {
        printf("mysignal SIGINT err : %m\n");
        return 0;
    }

    while (1)
        pause();

    return 0;
}
