#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int
main(void)
{
    int fd = 100;
    int fd_tmp = -1;

    fd_tmp = dup2(fd, fd);

    perror("err");

    printf("fd_tmp :%d\n", fd_tmp);

    exit(0);
}
