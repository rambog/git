#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <setjmp.h>

static jmp_buf jmpenv;
static sigjmp_buf sigjmpenv;

static void
sig_intr(int signo)
{
    printf("sigintr start\n");
    


    printf("sigintr end\n");
}

static void
sig_alrm(int signo)
{
    printf("sigalrm start\n");
    
    //longjmp(jmpenv, 1);
    //siglongjmp(sigjmpenv, 1);
    struct sigaction alrmold; 
    if (sigaction(SIGALRM, NULL, &alrmold) < 0) {
        perror("sigaction get alrm old err");
        return;
    }

    sigdelset(&alrmold.sa_mask, SIGINT);
    if (sigaction(SIGALRM, &alrmold, NULL) < 0) {
        perror("sigaction del SINGINT err ");
        return;
    }

    longjmp(jmpenv, 1);
    printf("sigalarm end\n");
}

int
main(int argc, char *argv[])
{
    struct sigaction acintr, acalrm;

    sigemptyset(&acintr.sa_mask);
    acintr.sa_flags = 0;
    acintr.sa_handler = sig_intr;
    if (sigaction(SIGINT, &acintr, NULL) < 0) {
        perror("sigaciton SIGINT err");
        return 0;
    }

    sigemptyset(&acalrm.sa_mask);
    sigaddset(&acalrm.sa_mask, SIGINT); 
    acalrm.sa_flags = 0;
    acalrm.sa_handler = sig_alrm;
    if (sigaction(SIGALRM, &acalrm, NULL) < 0) {
        perror("sigaction SIGALRM err");
        return 0;
    }

    alarm(1);

    if (setjmp(jmpenv) == 0) {
        printf("jmpenv init\n");
    }

    if (setjmp(jmpenv) == 1) {
        alarm(9);
    }

#if 0
    sleep(5);
    struct sigaction alrmold; 
    if (sigaction(SIGALRM, NULL, &alrmold) < 0) {
        perror("sigaction get alrm old err");
        return 0;
    }

    sigdelset(&alrmold.sa_mask, SIGINT);
    if (sigaction(SIGALRM, &alrmold, NULL) < 0) {
        perror("sigaction del SINGINT err ");
        return 0;
    }
#endif

    printf("enter pause\n");
    for ( ; ; ) pause();

    return 0;
}
