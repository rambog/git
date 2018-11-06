#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>

static void
sig_chld(int signo)
{
    printf("enter sigchld handler\n");
    sleep(2);

    pid_t pid;
    pid = wait(NULL);
    if (pid < 0)
        printf("sigchld handler\n");
    else
        printf("sigchld:%lu handler\n", pid);
}

int
main(int argc, char *argv[])
{
    pid_t pid;

    signal(SIGCHLD, sig_chld);

    pid = fork();
    if (pid == 0) {
        printf("i am child1 %lu\n", getpid());
        sleep(1);
        exit(0);
    }
    pid = fork();
    if (pid == 0) {
        printf("i am child2 %lu\n", getpid());
        sleep(1);
        exit(0);
    }
    pid = fork();
    if (pid == 0) {
        printf("i am child3 %lu\n", getpid());
        sleep(1);
        exit(0);
    }
    pid = fork();
    if (pid == 0) {
        printf("i am child4 %lu\n", getpid());
        sleep(1);
        exit(0);
    }

    for ( ; ; )
        pause();

    return 0;
}
