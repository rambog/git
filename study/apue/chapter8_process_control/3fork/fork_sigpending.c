#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void
sig_intr(int signo)
{
    printf("enter sigintr handler\n");

    sleep(1);

    printf("quit sigintr handler\n");
}

int
main(void)
{
    if (signal(SIGINT, sig_intr) == SIG_ERR) {
        perror("signal SIGINT");
        return 0;
    }

    sigset_t newmask, oldmask;
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
        perror("sigprocmask err");
        return 0;
    }

    raise(SIGINT);
    printf("raise SIGINT\n");

    pid_t pid;
    pid = fork();
    if (pid < 0) {
        return 0;
    } else if (pid == 0) {
        sigset_t maskpend;
        sigemptyset(&maskpend);
        for ( ; ; ) {
            if (sigpending(&maskpend) < 0) {
                perror("sigpending err");
                return 0;
            } 

            if (sigismember(&maskpend, SIGINT)) {
                printf("child pending sigint\n");
            } else {
                printf("child nor sigint\n");
            }
            sleep(1);
        }
    } else {
        sigset_t fmaskpend;
        sigemptyset(&fmaskpend);
        for ( ; ; ) {
            if (sigpending(&fmaskpend)) {
                perror("sigpending err");
                return 0;
            }

            if (sigismember(&fmaskpend, SIGINT)){
                printf("parent pending sigint\n");
            } else {
                printf("parent nor sigint\n");
            }
            sleep(1);
        }
    }
}
