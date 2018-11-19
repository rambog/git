#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <poll.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

int
main()
{
    int fd = open("tmp.txt", O_CREAT|O_RDWR, S_IRWXU);
    if (fd < 0) exit(0);

    struct pollfd pollfdset[2];

    memset(&pollfdset[0], 0x00, sizeof(struct pollfd));
    memset(&pollfdset[1], 0x00, sizeof(struct pollfd));

    pollfdset[0].fd = fd;
    pollfdset[0].events |= POLLIN;
    pollfdset[0].events |= POLLOUT;

    pollfdset[1].fd = 10;
    pollfdset[1].events |= POLLIN;
    pollfdset[1].events |= POLLOUT;

    int err = poll(pollfdset, 2, 1000*1000);
    if (err < 0) perror("poll err");

    if (pollfdset[0].revents & POLLIN)
        printf("pollfd0 can read\n");

    if (pollfdset[0].revents & POLLOUT)
        printf("pollfd0 can write\n");

    if (pollfdset[1].revents & POLLIN)
        printf("pollfd1 can read\n");

    if (pollfdset[1].revents & POLLOUT)
        printf("pollfd1 can write\n");

    if (pollfdset[1].revents & POLLNVAL)
        printf("pollfd1 nval\n");

    return 0;
}
