#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int
main(void)
{
    int fdout = fileno(stdout); 
    if (fdout < 0) return 0;
    printf("stdout fd : %d %d\n", fdout, STDOUT_FILENO);

    int fdin = fileno(stdin);
    if (fdin < 0) return 0;
    printf("stdin fd : %d %d\n", fdin, STDIN_FILENO);

    int fderr = fileno(stderr);
    if (fderr < 0) return 0;
    printf("stderr fd : %d %d\n", fderr, STDERR_FILENO);

    struct flock flout, flin, flerr;
    int err;

    flout.l_type = F_RDLCK;
    flout.l_whence = SEEK_SET;
    flout.l_start = 0;
    flout.l_len = 0;
    err = fcntl(fdout, F_GETLK, &flout);
    if (err == -1) perror("fcntl err");
    if (flout.l_type == F_UNLCK)
        printf("can lock\n");
    else
        printf("can't lock\n");

    flout.l_type = F_WRLCK;
    err = fcntl(fdout, F_SETLK, &flout);
    if (err < 0) perror("fcntl set WRLCK err");

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        char *foo = "i am child\n";
        err = write(fdout, foo, strlen(foo));
        if (err < 0) perror("write err");
        exit(0);
    }

    waitpid(pid, NULL, 0);

    return 0;
}
