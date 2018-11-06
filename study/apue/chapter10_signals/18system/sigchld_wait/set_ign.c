#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

static void
sig_chld(int signo)
{
    printf("in sigchld handler\n");

    printf("exit sigchld handler\n");
}

int
main(int argc, char *argv[])
{
    pid_t pid;

    //signal(SIGCHLD, SIG_IGN);
    signal(SIGCHLD, sig_chld);

    pid = fork();
    if (pid == 0) {
        sleep(1);
        exit(0);
    }

    if (waitpid(pid, NULL, 0) < 0) {
        perror("waitpid err");
    } else {
        printf("waitpid[%lu], success\n", pid);
    }

    for ( ; ; )
        pause();

    exit(0);
}
