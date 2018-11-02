#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <signal.h>

static void
sig_func(int signo)
{
    printf("cur signal to pid:%ld\n", getpid());
    if (signo == SIGCHLD)
        printf("recv child exit\n");
}

int
main(int argc, char *argv[])
{
    pid_t pid;
    signal(SIGCHLD, sig_func);
    //signal(SIGCLD, SIG_IGN);
    //signal(SIGCHLD, SIG_IGN);

    pid = fork();

    if (pid < 0)
        perror("fork err");
    else if (pid == 0) {
        printf("i am child pid:%ld\n", getpid());
        sleep(2);
        exit(0);
    } else {
        printf("i am parent pid:%ld\n", getpid());

        if (pid == wait(NULL))
            printf("normal wait child:%ld\n", pid);
        else
            perror("wait err");
    }

    return 0;
}
