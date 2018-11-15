#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 0;
    }

    int fd = open(argv[1], O_RDWR);
    if (fd < 0) perror("child open err");

    int err;
    char *foo = "child_qwertyui\n";
    struct flock flck;
    memset(&flck, 0x00, sizeof(struct flock));
    flck.l_type = F_WRLCK;
    flck.l_whence = SEEK_SET;
    flck.l_start = 0;
    flck.l_len = 8;
    err = fcntl(fd, F_GETLK, &flck);
    if (err < 0) perror("fcntl getlk err");
    if (flck.l_type != F_UNLCK) {
        printf("child process%ld ocuppy the flock\n", flck.l_pid);
        err = write(fd, foo, strlen(foo)); 
        if (err < 0) perror("write err");
    }

    exit(0);
}
