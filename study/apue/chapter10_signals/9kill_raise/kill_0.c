#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

static void
sig_chld(int signo)
{
    if (signo == SIGCHLD) {
        pid_t pid;
        pid = wait(NULL);
        if (pid > 0) 
            printf("wait for pid : %u\n", pid);
        else
            perror("wait err");
    }
}

int
main(int argc, char *argv[])
{
    pid_t pid;

    signal(SIGCHLD, sig_chld);

    pid = fork();

    if (pid < 0) {
        return 0;
    }

    if (pid == 0) {
        sleep(3);
        exit(0);
    }

    for ( ; ; ) {
        if (0 == kill(pid, 0))
            printf("send sucess\n");
        else {
            printf("send failed\n");
            break;
        }

        usleep(400*1000);
    }

    return 0;
}
