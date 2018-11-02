#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

static void
my_sigalrm(int signo)
{
    if (signo == SIGALRM) {
        printf("get sigalrm \n");
        sleep(10);
    }
}

int
main(int argc, char *argv[])
{
    signal(SIGALRM, my_sigalrm);

    unsigned int remain;

    remain = alarm(1);
    sleep(2);

    remain = alarm(1);
    sleep(2);

    remain = alarm(0);
    sleep(2);

    while (1) 
        pause();

    return 0;
}
