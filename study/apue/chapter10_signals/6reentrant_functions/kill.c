#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>

#define PRINTSIG(signo) printf("get sig[%d] : %s\n", signo, #signo)

static void 
sig_func(int signo)
{
    switch (signo) {
        case SIGINT :
            PRINTSIG(SIGINT);
            break;
        case SIGQUIT :
            PRINTSIG(SIGQUIT);
            break;
        case SIGTSTP :
            PRINTSIG(SIGTSTP);
            break;
        default :
            return;
    }
}

int
main(int argc, char *argv[])
{
    signal(SIGINT, sig_func);
    signal(SIGQUIT, sig_func);
    signal(SIGTSTP, sig_func);

    kill(getpid(), SIGINT);
    kill(getpid(), SIGTSTP);
    kill(getpid(), SIGQUIT);
    kill(getpid(), SIGUSR1);

    for ( ; ; )
        pause();

    return 0;
}
