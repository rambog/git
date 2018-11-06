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

    //signal(SIGCHLD, SIG_IGN);
    signal(SIGCHLD, sig_chld);

#if 2
    pid = fork();
    if (pid == 0) {
        printf("i am noblock pid : %lu\n", getpid());
        sleep(4);
        exit(0);
    }
#endif

    sigset_t newmask, oldmask;
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGCHLD);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);

    pid = fork();
    if (pid == 0) {
        printf("i am block pid : %lu\n", getpid());
        sleep(3);
        exit(0);
    }

    if (waitpid(pid, NULL, 0) < 0) {
        perror("waitpid err");
    } else {
        printf("waitpid[%lu], success\n", pid);
    }

    sigprocmask(SIG_SETMASK, &oldmask, NULL);

    for ( ; ; )
        pause();

    exit(0);
}
