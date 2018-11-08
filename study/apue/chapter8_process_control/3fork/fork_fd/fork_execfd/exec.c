#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    char tmp[128];
    memset(tmp, 0x00, sizeof(tmp));

    int fd = atoi(argv[1]);
    printf("child fd : %d filename:%s\n", fd, argv[2]);

    sleep(3);
    sprintf(tmp, "child : %ld\n", getpid());

    if (write(fd, tmp, strlen(tmp)) < 0) {
        perror("write err");
        fd = open(argv[2], O_RDWR);
        if (fd < 0) {
            perror("open err");
            return 0;
        }
        if (write(fd, tmp, strlen(tmp)) < 0) {
            perror("write err again");
            return 0;
        }
    }

    return 0;
}
