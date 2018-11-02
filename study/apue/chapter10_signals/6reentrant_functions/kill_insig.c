#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>

#define PRINTSIG(signo) printf("get sig[%d] : %s\n", signo, #signo)

pid_t pid_self;

static void 
sig_func(int signo)
{
    switch (signo) {
        case SIGINT :
            PRINTSIG(SIGINT);
            kill(pid_self, SIGINT);
            break;
        case SIGQUIT :
            PRINTSIG(SIGQUIT);
            exit(0);
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
    pid_self = getpid();

    signal(SIGINT, sig_func);
    signal(SIGQUIT, sig_func);
    signal(SIGTSTP, sig_func);

    kill(getpid(), SIGINT);

    for ( ; ; )
        pause();

    return 0;
}
