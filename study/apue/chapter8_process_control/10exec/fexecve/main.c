#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;

int
main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open err");
        return 0;
    }

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        fexecve(fd, argv, environ);
        perror("fexecve err");
        exit(0);
    }

    if (pid != wait(NULL)) {
        perror("wait err");
    }

    exit(0);
}
