#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

static void
my_sigalrm(int signo)
{
    if (signo == SIGALRM) {

    }
}

int
main(int argc, char *argv[])
{
    signal(SIGALRM, my_sigalrm);

    unsigned int remain;

    remain = alarm(5);
    printf("first alarm remain : %u\n", remain);

    sleep(2);

    remain = alarm(1);
    printf("second alarm remain : %u\n", remain);

    while (1) 
        pause();

    return 0;
}
