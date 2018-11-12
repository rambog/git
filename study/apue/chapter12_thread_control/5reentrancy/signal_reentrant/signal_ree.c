#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

static void
sig_intr(int signo)
{
    printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
}

int
main(void)
{
    if (signal(SIGINT, sig_intr) == SIG_ERR) return 0;

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        while (1) {
            printf("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n");
            usleep(1000);
        }
        exit(0);
    }

    while (1)
        kill(pid, SIGINT);

    return 0;
}
