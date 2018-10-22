#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int
main(void)
{
    struct stat statbuf;

    int sysret;
    int fd;

    fd = open("./", O_RDONLY);
    if (fd < 0) {
        printf("open err : %m\n");
        return 1;
    }

    sysret = fstat(fd, &statbuf);
    if (sysret < 0) {
        printf("fstat err : %m\n");
        return 1;
    }

    if (S_ISDIR(statbuf.st_mode))
        printf("cur stat is dir\n");

    printf("cur dir links : %u\n", statbuf.st_nlink);

    exit(0);
}
