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

    pid_t pid;
    pid = wait(NULL);
    if (pid < 0) 
        perror("wait err");
    else
        printf("wait child : %lu exit\n", pid);

    printf("exit sigchld handler\n");
}

int
main(int argc, char *argv[])
{
    pid_t pid;

    signal(SIGCHLD, sig_chld);

    sigset_t newmask, oldmask;
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGCHLD);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);

    pid = fork();
    if (pid == 0) {
        printf("i am child1 pid : %lu\n", getpid());
        sleep(1);
        exit(0);
    }
    
    pid = fork();
    if (pid == 0) {
        printf("i am child2 pid : %lu\n", getpid());
        sleep(2);
        exit(0);
    }

    pid = fork();
    if (pid == 0) {
        printf("i am child3 pid : %lu\n", getpid());
        sleep(3);
        exit(0);
    }

    sleep(5);
    sigprocmask(SIG_SETMASK, &oldmask, NULL);

    for ( ; ; )
        pause();

    exit(0);
}
