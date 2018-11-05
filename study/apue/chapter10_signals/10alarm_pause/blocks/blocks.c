#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#define MAXLINE 4096

static void sig_alrm(int);

int
main(void)
{
    int n;
    char line[MAXLINE];

#if 0
    int fsl;
    fsl = fcntl(STDIN_FILENO, F_GETFL);
    fsl |= O_NONBLOCK;
    fcntl(STDIN_FILENO, F_SETFL, fsl);
#endif

    if (signal(SIGALRM, sig_alrm) ==SIG_ERR) {
        printf("signal(SIGALRM) error : %m\n");
        return 1;
    }


    alarm(10);

    if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0) {
        printf("read error : %m\n");
        return 1;
    }
    alarm(0);

    write(STDOUT_FILENO, line, n);
    exit(0);
}

static void
sig_alrm(int signo)
{
}
