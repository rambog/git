#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/select.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>

int
main()
{
    fd_set readset, writeset, exceptset;

    FD_ZERO(&readset);
    FD_ZERO(&writeset);
    FD_ZERO(&exceptset);

    struct timespec timeout;

    timeout.tv_sec = 50;
    timeout.tv_nsec = 0;

    sigset_t mask; 
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);

    pselect(5, NULL, NULL, NULL, &timeout, &mask);

    return 0;
}
