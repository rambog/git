#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/select.h>
#include <fcntl.h>
#include <time.h>

int
main()
{
    int fd = open("tmp.txt", O_RDWR|O_CREAT, S_IRWXU);
    if (fd < 0) exit(0);

    fd_set readset, writeset, exceptset;

    FD_ZERO(&readset);
    FD_ZERO(&writeset);
    FD_ZERO(&exceptset);

    FD_SET(fd, &readset);
    FD_SET(fd, &writeset);
    FD_SET(fd, &exceptset);

    struct timeval timeout;

    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    int err;

    err = select(fd+1, &readset, &writeset, &exceptset, &timeout);
    if (err < 0) perror("select err");
    else if (err == 0) printf("select timeout\n");
    else if (err > 0) {
        if (FD_ISSET(fd, &readset))
            printf("fd:%d ready in readset\n", fd);
        if (FD_ISSET(fd, &writeset))
            printf("fd:%d ready in writeset\n", fd);
        if (FD_ISSET(fd, &exceptset))
            printf("fd:%d ready in exceptset\n", fd);
    }

    return 0;
}
