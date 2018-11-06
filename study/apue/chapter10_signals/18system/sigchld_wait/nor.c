#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

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
    void (*bef)(int);

    //bef = signal(SIGCHLD, sig_chld);
    if (bef == SIG_ERR) {
        perror("signal SIGCHLD");
        return 0;
    } else if (bef == SIG_IGN) {
        printf("bef is SIG_IGN\n");
    } else if (bef == SIG_DFL) {
        printf("bef is SIG_DFL\n");
    } else {
        printf("bef is signal reg\n");
    }

    if (wait(NULL) < 0)
        perror("wait err");

    pid = fork();
    if (pid < 0) {
        return 0;
    } else if (pid == 0) {
        sleep(1);
        exit(0);
    }

    sleep(5);

    if (waitpid(pid, NULL, 0) < 0)
        perror("waitpid err");

    printf("main exit\n");

    exit(0);
}
