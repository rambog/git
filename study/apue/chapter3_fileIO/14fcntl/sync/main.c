#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int
main(void)
{
    int fd = open("file.txt", O_RDWR|O_CREAT|O_EXCL, 777);
    if (fd < 0) {
        perror("open err");
        return 1;
    }

    int flag;

    if ((flag = fcntl(fd, F_GETFL, 0)) < 0) {
        perror("fcntl F_GETFL err");
        return 1;
    }

    //flag |= O_SYNC;
    flag &= ~O_SYNC;

    if (fcntl(fd, F_SETFL, flag) < 0) {
        perror("fcntl F_SETFL err");
        return 1;
    }

    char buf[16] = {0x00};
    sprintf(buf, "%s", "I am rambo");
    write(fd, buf, strlen(buf));

    for ( ; ; )
        sleep(1);

    exit(0);
}
