#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage : %s <exe_file>\n", argv[0]);
        return 1;
    }

    int fd = -1;
    fd = open("file.txt", O_RDWR|O_CREAT|O_EXCL, 777);
    if (fd < 0)
        perror("open err");
        
    int flag;
    if (flag = fcntl(fd, F_GETFD, 0) < 0) {
        perror("fcntl F_GETFD");
        return 1;
    }
    
    flag |= FD_CLOEXEC;

    if (fcntl(fd, F_SETFD, flag) < 0) {
        perror("fcntl F_SETFD");
        return 1;
    }

    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork err");
        return 1;
    } else if (pid == 0) {
        char fd_str[8] = {0x00};
        sprintf(fd_str, "%d", fd);
        execl(argv[1], argv[1], fd_str, NULL);
    } else {
        char buf[16] = {0x00};
        sprintf(buf, "%s", "i am origin\n");
        ssize_t nwr;
        for ( ; ; ) {
           nwr = write(fd, buf, strlen(buf)); 
           if (nwr < 0) {
               perror("write err");
               return 0;
           }
           sleep(1);
        }
    }

    exit(0);
}
