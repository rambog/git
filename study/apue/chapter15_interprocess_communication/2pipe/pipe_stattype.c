#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

int
main(void)
{
    struct stat statbuf;
    int pipefd[2];
    
    if (0 != pipe(pipefd)) {
        perror("pipe err");
        return 0;
    }

    if (0 != fstat(pipefd[0], &statbuf)) perror("fstat err");

    if (S_ISFIFO(statbuf.st_mode))
        printf("fd[0] is fifo\n");

    if (statbuf.st_mode & S_IRUSR)
        printf("fd[0] is read\n");

    if (statbuf.st_mode & S_IWUSR)
        printf("fd[0] is write\n");

    if (0 != fstat(pipefd[0], &statbuf)) perror("fstat err");

    if (S_ISFIFO(statbuf.st_mode))
        printf("fd[1] is fifo\n");

    if (statbuf.st_mode & S_IRUSR)
        printf("fd[1] is read\n");

    if (statbuf.st_mode & S_IWUSR)
        printf("fd[1] is write\n");

    return 0;
}
