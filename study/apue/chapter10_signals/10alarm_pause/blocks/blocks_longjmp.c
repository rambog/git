#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <setjmp.h>

#define MAXLINE 4096

static jmp_buf jmpenv;

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

#if 1
    if (setjmp(jmpenv) == 1) { 
        //printf("jmpenv init\n");
        printf("return 1\n");
        return 1;
    }
#endif

    printf("enter alarm\n");
    alarm(3);
    //setjmp(jmpenv) == 1;

    printf("enter readblock\n");
    if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0) {
        printf("read error : %m\n");
        return 1;
    }

    if (setjmp(jmpenv) == 2) {
        printf("return by sigalrm\n");
        return 0;
    }

    alarm(0);

    write(STDOUT_FILENO, line, n);
    exit(0);
}

static void
sig_alrm(int signo)
{
    longjmp(jmpenv, 3);
}
