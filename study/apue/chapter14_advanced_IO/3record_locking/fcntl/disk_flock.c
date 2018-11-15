#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int
main()
{
    int fdf = open("tmp.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
    if (fdf < 0) perror("father open err");

    struct flock fflock;
    memset(&fflock, 0x00, sizeof(struct flock));
    int ferr;

    fflock.l_type = F_WRLCK;
    fflock.l_whence = SEEK_SET;
    fflock.l_start = 0;
    fflock.l_len = 0;
    ferr = fcntl(fdf, F_SETLKW, &fflock);
    if (ferr < 0) perror("father setlkw err");

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        close(fdf);
        printf("I am child : %ld\n", (long)getpid());

        int cdf = open("tmp.txt", O_RDWR);
        if (cdf < 0) perror("child open err");

        struct flock cflock;
        int cerr;

        memset(&cflock, 0x00, sizeof(struct flock));

        cflock.l_type = F_WRLCK;
        cflock.l_whence = SEEK_SET;
        cflock.l_start = 0;
        cflock.l_len = 0;
        cerr = fcntl(cdf, F_GETLK, &cflock);
        if (cerr < 0) perror("child getlk err");
        if (cflock.l_type == F_UNLCK)
            printf("child curlock can lock\n");
        else
            printf("child curfile lock by process:%ld\n", cflock.l_pid);

        cflock.l_type = F_WRLCK;
        cerr = fcntl(cdf, F_SETLK, &cflock);
        if (cerr < 0) perror("child setlk err");

        exit(0);
    }

    printf("I am parent : %ld\n", (long)getpid());
    if (pid == waitpid(pid, NULL, 0))
        printf("wait pid %ld\n", (long)pid);

    exit(0);
}
