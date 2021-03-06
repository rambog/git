#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int
main(void)
{
    int fd = open("tmp.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
    if (fd < 0) perror("open err");

    printf("F_GETLK:%d F_SETLK:%d F_SETLKW:%d\n", F_GETLK, F_SETLK, F_SETLKW);
    printf("F_RDLCK:%d F_WRLCK:%d F_UNLCK:%d\n", F_RDLCK, F_WRLCK, F_UNLCK);

    struct flock flck;
    int err;
    char *foo = "paren_asdfghjk\n";
    err = write(fd, foo, strlen(foo));
    if (err < 0) perror("write err");

    flck.l_type = F_WRLCK;
    flck.l_whence = SEEK_SET;
    flck.l_start = 0;
    flck.l_len = 0;
    err = fcntl(fd, F_GETLK, &flck);
    if (err < 0) perror("fcntl err");
    if (flck.l_type != F_UNLCK)
        printf("flck probe failed locked pid:%ld\n", flck.l_pid);

    flck.l_type = F_WRLCK;
    err = fcntl(fd, F_SETLKW, &flck);
    if (err < 0) perror("fcntl err");

    pid_t pid ;
    pid = vfork();
    if (pid == 0) {
        //close(fd);
        //fd = open("tmp.txt", O_RDWR);
        //if (fd < 0) perror("child open err");
        printf("I am child : %ld\n", (long)getpid());
        memset(&flck, 0x00, sizeof(struct flock));

        flck.l_type = F_WRLCK;
        flck.l_whence = SEEK_SET;
        flck.l_start = 0;
        flck.l_len = 0;
        err = fcntl(fd, F_GETLK, &flck);
        if (err < 0) perror("fcntl err");
        if (flck.l_type != F_UNLCK)
            printf("child try flock failed\n");
        else printf("file not lock : %ld\n", (long)flck.l_type);

        flck.l_type = F_WRLCK;
        err = fcntl(fd, F_SETLK, &flck);
        if (err < 0) perror("fcntl setlk err");

        foo = "child_qwertyui\n";
        err = write(fd, foo, strlen(foo));
        if (err < 0) perror("write err");

        printf("child will exit\n");
        exit(0);
    }

    printf("I am parent : %ld\n", (long)getpid());
    pid = waitpid(pid, NULL, 0);
    if (pid < 0) perror("waitpid err");
    else printf("wait child:%ld\n", (long)pid);
    
    return 0;
}
