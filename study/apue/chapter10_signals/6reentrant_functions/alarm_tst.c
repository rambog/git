#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>

static void
my_alarm(int signo)
{
    if (signo == SIGALRM)
    {
        printf("trigger alarm sig\n");
        alarm(1);
    }
}

int
main(int argc, char *argv[])
{
    signal(SIGALRM, my_alarm);
    alarm(1);

    for ( ; ; )
        pause();

    return 0;
}
