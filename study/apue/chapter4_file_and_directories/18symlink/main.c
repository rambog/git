#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char *argv[], char *envp)
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 1;
    }

    int sysret;
    char newsym[32];
    memset(newsym, 0x00, sizeof(newsym));
    sprintf(newsym, "%s%s", argv[1], "_sym");

    sysret = symlink(argv[1], newsym);
    if (sysret != 0) {
        printf("symlink err : %m\n");
        return 1;
    }

    char readbuf[64];
    memset(readbuf, 0x00, sizeof(readbuf));

    sysret = readlink(newsym, readbuf, sizeof(readbuf));
    if (sysret == -1) {
        printf("readlink err : %m\n" );
    }
    printf("readlink read symbol link : %s\n", readbuf);

    int fd;
    fd = open(newsym, O_RDWR);
    if (fd < 0) {
        printf("open err : %m\n");
        return 1;
    }

    ssize_t sread;
    sread = read(fd, readbuf, sizeof(readbuf));
    if (sread < 0) {
        printf("read err[%u] : %m\n", errno);
        return 1;
    }
    printf("open follow symbol link read : %s\n", readbuf);

    close(fd);

    fd = open(newsym, O_RDWR|O_NOFOLLOW);
    if (fd < 0) {
        printf("open err[%d] : %m\n", errno);
        return 1;
    }

    exit(0);
}
