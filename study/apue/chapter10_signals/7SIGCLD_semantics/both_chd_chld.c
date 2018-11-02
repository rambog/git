#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void sigchd_func(int signo)
{
    if (signo == SIGCLD)
        printf("get SIGCLD : %d\n", SIGCLD);
}

static void sigchld_func(int signo)
{
    if (signo == SIGCHLD)
        printf("get SIGCHLD : %d\n", SIGCHLD);
}

int
main(int argc, char *argv[])
{
    signal(SIGCLD, sigchd_func);
    signal(SIGCHLD, sigchld_func);

    pid_t pid;

    pid = fork();
    if (pid < 0) {
        perror("fork err");
        return 0;
    } else if (pid == 0) {
        sleep(2);
        return 0;
    }

    if (pid == wait(NULL))
        printf("wait normal\n");
    else 
        perror("wait err");

    return 0;
}
