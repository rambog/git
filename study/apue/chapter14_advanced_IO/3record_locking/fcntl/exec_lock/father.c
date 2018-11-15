#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("usage : %s <file> <childexec>\n", argv[0]);
        return 0;
    }

    printf("I am parent : %ld\n", (long)getpid());
    int fd = open(argv[1], O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
    if (fd < 0) perror("open err");

    struct flock flck;
    int err;
    int status;

    //status = fcntl(fd, F_GETFD);
    //status |= FD_CLOEXEC;
    //fcntl(fd, F_SETFD, &status);

    flck.l_type = F_WRLCK;
    flck.l_whence = SEEK_SET;
    flck.l_start = 0;
    flck.l_len = 0;
    err = fcntl(fd, F_GETLK, &flck);
    if (err < 0) perror("fcntl getlk err");
    if (flck.l_type == F_UNLCK) {
        flck.l_type = F_WRLCK;
        err = fcntl(fd, F_SETLK, &flck);
        if (err < 0) perror("fcntl setlk err");
    } else printf("process %ld occupy lock\n", flck.l_pid);

    pid_t pid = vfork();
    if (pid == 0) {
        execl(argv[2], argv[2], argv[1], NULL);
        perror("execl err");
        exit(0);
    }

    waitpid(pid, NULL, 0);
    printf("parent exit\n");
    exit(1);
}
