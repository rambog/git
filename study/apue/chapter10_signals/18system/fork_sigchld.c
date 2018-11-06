#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void
sig_chld(int signo)
{
    if (signo == SIGCHLD) {
        printf("in SIGCHLD handler\n");

        //printf("wait pid : %d\n", wait(NULL));

        printf("end SIGCHLD handler\n");
    }
}

int
main(int argc, char *argv[])
{
    if (signal(SIGCHLD, sig_chld) == SIG_ERR) {
        perror("signal SIGCHLD");
        return 0;
    }

    pid_t pid;

    pid = fork();
    if (pid < 0) {
        return 0;
    } else if (pid == 0) {
        printf("I am first child[%lu]\n", getpid());
        sleep(2);
        exit(0);
    }

#if 1
    sigset_t setmask, oldmask;
    sigemptyset(&setmask);
    sigaddset(&setmask, SIGCHLD);
    sigprocmask(SIG_BLOCK, &setmask, &oldmask);

    pid_t syspid;
    syspid = fork();
    if (syspid < 0)
        return 0;
    else if (syspid == 0) {
        printf("I am system child[%lu]\n", getpid());
        sleep(3);
        exit(0);
    }
    sleep(4);

    if (waitpid(syspid, NULL, 0) < 0) {
        perror("waitpid err");
    } else {
        printf("wait pid:%lu, end\n", syspid);
    }

    sigprocmask(SIG_SETMASK, &oldmask, NULL);
#endif
     
    while (1) pause();

    return 0;
}
