#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int
main(void)
{
    int fd;
    if ((fd = open("tempfile", O_RDWR)) < 0)
        return -1;

    close(fd);

    if (unlink("tempfile") < 0)
        printf("%m\n");

    printf("file unlinked\n");

    sleep(15);

    printf("done\n");
    exit(0);
}
