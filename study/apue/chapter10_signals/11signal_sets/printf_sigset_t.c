#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void
printf_sigbits(char *, sigset_t *);

int
main(int argc, char *argv[])
{
    sigset_t sigset;
    //printf_sigbits("ori sigset", &sigset);

    sigemptyset(&sigset);
    printf_sigbits("emptyset", &sigset);

    //sigfillset(&sigset);
    //printf_sigbits("fillset", &sigset);
    
    sigaddset(&sigset, SIGALRM);
    printf_sigbits("add sigalrm", &sigset);

    sigdelset(&sigset, SIGALRM);
    printf_sigbits("delete sigalrm", &sigset);
}

void
printf_sigbits(char *printstr, sigset_t *sigset)
{
    int i;
    printf("\n%s\n", printstr);
    for (i = 0; i < sizeof(sigset_t)/sizeof(unsigned long int); i++) {
        printf("%2d : %64llx\n", i, sigset->__val[i]);
    }
}
