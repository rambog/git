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
    pid = fork();
    if (pid < 0) {
        perror("fork err");
        return 1;
    } else if (pid == 0) {
        //off_t cur;
        for ( ; ; ) {
            if ((cur = lseek(fd, 0, SEEK_CUR)) == -1) {
                perror("lseek err");
                return 1;
            }

            printf("I am child proc fd[%lu] seek is :%d\n", fd, cur);

            sleep(1);
        }
    } else {
        //off_t cur;
        for ( ; ; ) {
            if ((cur = lseek(fd, 1, SEEK_CUR)) == -1) {
                perror("lseek err");
                return 1;
            }

            printf("I am father proc fd[%lu] seek is :%d\n", fd, cur);

            sleep(1);
        }
    }

    exit(0);
}
