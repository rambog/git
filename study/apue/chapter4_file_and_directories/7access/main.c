#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return -1;
    }

    if (access(argv[1], F_OK) < 0) {
        printf("file not exist\n");
        return 0;
    }

    if (access(argv[1], R_OK) == 0) {
        printf("can read\n");
    }
    
    if (access(argv[1], W_OK) == 0) {
        printf("can write\n");
    }

    if (access(argv[1], X_OK) == 0) {
        printf("can exe\n");
    }

    int fd = 0;
    if ((fd = open(argv[1], O_RDONLY)) > 0)
        printf("open can read\n");
    close(fd);
    if ((fd = open(argv[1], O_WRONLY)) > 0)
        printf("open can write\n");
    close(fd);
    if ((fd = open(argv[1], O_RDWR)) > 0)
        printf("open can read and write\n");
    close(fd);

    exit(0);
}
