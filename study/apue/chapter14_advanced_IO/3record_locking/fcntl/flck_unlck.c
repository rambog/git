#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int
main(void)
{
    int err;
    int fd = open("tmp.txt", O_CREAT|O_RDWR, S_IRWXU);
    if (fd < 0) exit(0);

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 16;
    err = fcntl(fd, F_SETLK, &lock);
    if (err < 0) perror("parent set flock err");

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 4;
    lock.l_len = 4;
    err = fcntl(fd, F_SETLK, &lock);
    if (err < 0) perror("parent set unlck err");

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        err = fcntl(fd, F_GETLK, &lock);
        if (err < 0) perror("child get lck err");
        if (lock.l_type != F_UNLCK) {
            printf("get lock type : %d\n", lock.l_type);
        }
        exit(0);
    }

    waitpid(pid, NULL, 0);
    
    return 0;
}
