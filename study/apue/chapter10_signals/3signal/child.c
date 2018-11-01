#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

#define PRINTSIG(SIGNO) printf("catch sig[%d] : %s\n", SIGNO, #SIGNO)

static void
sig_func(int signo)
{
    switch (signo) {
        case SIGINT :
            PRINTSIG(SIGINT);
            break;
        default :
            break;
    }
}


int
main(int argc, char *argv[], char *envp[])
{
    int i = 0;
    for (i = 0; argv[i] != NULL; i++)
        printf("env[%d] : %s\n", i, argv[i]);

    if (signal(SIGINT, sig_func) == SIG_ERR)
        perror("reg SIGINT err");

    pause();

    return 0;
}
