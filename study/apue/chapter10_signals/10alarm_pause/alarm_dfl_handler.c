#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

static void
my_sigalrm(int signo)
{
    if (signo == SIGALRM) {

    }
}

int
main(int argc, char *argv[])
{
    signal(SIGALRM, SIG_IGN);

    alarm(1);

    while (1) 
        pause();

    return 0;
}
