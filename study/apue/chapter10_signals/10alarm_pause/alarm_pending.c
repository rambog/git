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
    printf("1 alarm 1s\n");
    sleep(2);

    remain = alarm(1);
    printf("2 alarm 1s\n");
    sleep(2);

    remain = alarm(0);
    printf("1 alarm 0s\n");
    sleep(2);

    while (1) 
        pause();

    return 0;
}
