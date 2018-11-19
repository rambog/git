#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/select.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

void
sig_intr(int signo)
{
    printf("in sig_intr\n");
}

int
main(void)
{
    struct timeval timeout;

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    signal(SIGINT, sig_intr);

    int err;
    err = select(1, NULL, NULL, NULL, &timeout);
    printf("err : %d\n", err);
    perror("select err");

    return 0;
}
