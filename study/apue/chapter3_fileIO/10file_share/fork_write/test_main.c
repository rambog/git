#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int
main(void)
{
    pid_t pid;

    int fd = open("file.txt", O_RDWR|O_EXCL, 777);
    if (fd < 0) {
        perror("open err");
        return 1;
    }

    off_t cur;
    for ( ; ; ) {
        if ((cur = lseek(fd, 0, SEEK_CUR)) == -1) {
            perror("lseek err");
            return 1;
        }

        printf("I am new proc fd[%lu] seek is :%d\n", fd, cur);

        sleep(1);
    }

    exit(0);
}
