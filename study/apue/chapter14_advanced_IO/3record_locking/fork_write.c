#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>

int
main(void)
{
    int fd = open("tmp.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
    if (fd < 0) perror("open err");

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        sleep(1);
        char *tmp = "qwertyui";
        ssize_t rn;
        rn = write(fd, tmp, strlen(tmp));
        if (rn < 0) perror("child wirte err");
        exit(0);
    }

    char *tmp = "asdfghjk";
    write(fd, tmp, strlen(tmp));

    exit(1);
}
