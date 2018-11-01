#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

static void sig_func(int);

int
main(int argc, char *argv[])
{
    int sysret;

    signal(SIGINT, sig_func);
    signal(SIGQUIT, sig_func);
    signal(SIGTSTP, sig_func);

#if 0
    while (1) {
        sysret = pause();
        if (sysret == -1)
            perror("pause err");
    }
#endif

    pid_t pid;

    pid = fork();
    if (pid < 0)
        return 0;
    else if (pid == 0) {
        while (1) {
            sysret = pause();
            if (sysret == -1)
                perror("child pause err");
        }
    }

    while (-1 == wait(NULL)) {
        perror("parent child err");
    }

    return 0;
}

static void
sig_func(int signo)
{
    if (signo == SIGQUIT)
        exit(0);
}
