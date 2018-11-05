#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void
sig_intr(int signo)
{
    if (signo == SIGINT) {
        printf("beg SIGINT in sigcautch\n");

        //sleep(1);    

        printf("end SIGINT in sigcautch\n\n");
    }
}

static void
sig_alrm(int signo)
{
    if (signo == SIGALRM) {
        printf("beg SIGALRM in sigcautch\n");

        sleep(1);

        printf("end SIGALRM in sigcautch\n");
    }
}

int
main(int argc, char *argv[])
{
    struct sigaction sigac; 
    int i;

    memset(&sigac, 0x00, sizeof(struct sigaction));
    sigemptyset(&sigac.sa_mask);
    sigac.sa_handler = sig_intr;
    if (sigaction(SIGINT, &sigac, NULL) < 0) {
        printf("sigaction err : %m\n");
        return 0;
    }

#if 0
    memset(&sigac, 0x00, sizeof(struct sigaction));
    sigemptyset(&sigac.sa_mask);
    sigac.sa_handler = sig_alrm;
    if (sigaction(SIGALRM, &sigac, NULL) < 0) {
        printf("sigaction err : %m\n");
        return 0;
    }
#else
    signal(SIGALRM, sig_alrm);
#endif

#if 0
    for (i = 0; i < 5; i++) {
        printf("kill SIGINT\n");
        raise(SIGINT);
    }
#endif

    for ( ; ; ) 
        pause();

    return 0;
}
