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
    int fd = open("tmp.txt", O_RDWR|O_CREAT, S_IRWXU);
    if (fd < 0) exit(0);
    write(fd, "fcntl test file\n", strlen("fcnlt test file\n"));

    struct flock lock;
    memset(&lock, 0x00, sizeof(struct flock));

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 4;
    err = fcntl(fd, F_SETLK, &lock);
    if (err < 0) perror("parent set f_rdlck err");
    printf("I am parent : %ld\n", (long)getpid());

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("I am first child : %ld\n", (long)getpid());
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 4;
        lock.l_len = 4;
        err = fcntl(fd, F_SETLK, &lock);
        if (err < 0) perror("first child set f_rdlck err");
        while (1) pause();
        exit(1);
    }

    sleep(1);
    pid = fork();
    if (pid == 0) {
        printf("I am second child : %ld\n", (long)getpid());
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 5;
        lock.l_len = 0;
        err = fcntl(fd, F_GETLK, &lock);
        if (err < 0) perror("second child set f_getlk err");
        if (lock.l_type != F_UNLCK) {
            printf("SEEK_SET:%d, SEEK_CUR:%d, SEEK_END:%d\n", SEEK_SET, SEEK_CUR, SEEK_END);
            printf("F_RDLCK:%d, F_WRLCK:%d, F_UNLCK:%d\n", F_RDLCK, F_WRLCK, F_UNLCK);
            printf("type:%d whence:%d start:%d len:%d pid:%ld\n", lock.l_type, lock.l_whence, lock.l_start, lock.l_len, lock.l_pid);
        }
        while (1) pause();
        exit(1);
    }

    wait(NULL);
    return 0;
}
