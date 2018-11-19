#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/uio.h>
#include <fcntl.h>

#define MAXIOVEC 8
#define MAXLEN 128

int
main(void)
{
    struct iovec iovec_list[MAXIOVEC];

    int i;
    for (i = 0; i < MAXIOVEC; i++) {
        iovec_list[i].iov_base = (void*)malloc(MAXLEN);
        if (iovec_list[i].iov_base == NULL) exit(0);

        sprintf(iovec_list[i].iov_base, "writev linenum:%d\n", i);

        iovec_list[i].iov_len = strlen((char*)iovec_list[i].iov_base);
    }

    int err;
    int fd = open("tmp.txt", O_RDWR|O_CREAT, S_IRWXU);
    if (fd < 0) exit(1);

    err = writev(fd, iovec_list, MAXIOVEC);
    if (err < 0) perror("writev err");

    close(fd);

    return 0;
}
