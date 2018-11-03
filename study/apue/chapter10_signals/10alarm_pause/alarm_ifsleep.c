#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>

static void
sig_alrm(int signo)
{
    if (signo == SIGALRM) {
        printf("pid : %ld get alarm\n", getpid());
    }
}

int
main(int argc, char *argv[])
{
    pid_t pid;
    signal(SIGALRM, sig_alrm);

    pid = fork();
    if (pid < 0) {
        perror("fork err");
        return 0;
    } else if (pid == 0) {
        printf("I am child %ld\n", getpid());
        //sleep(100);
        while (1) pause();
    }

    
    printf("I am parent %ld\n", getpid());
    kill(pid, SIGALRM);

    for ( ; ; )
        pause();

    return 0;
}
