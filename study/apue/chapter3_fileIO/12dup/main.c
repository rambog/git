#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define F1 "file1.txt"
#define F2 "file2.txt"
#define F3 "file3.txt"

#define FILE_MOD    O_RDWR

int
main(void)
{
    int fd1 = -1, fd2 = -1, fd3 = -1;
    int fd_tmp = -1;

    fd1 = open(F1, FILE_MOD, 777);
    if (fd1 < 0) printf("open %s err:%s\n", F1, strerror(errno));
    fd2 = open(F2, FILE_MOD, 777);
    if (fd2 < 0) printf("open %s err:%s\n", F2, strerror(errno));
    fd3 = open(F3, FILE_MOD, 777);
    if (fd3 < 0) printf("open %s err:%s\n", F3, strerror(errno));

    char buf[128] = {0x00};

    sprintf(buf, "%s", "I am fd1\n");
    write(fd1, buf, strlen(buf));

    sprintf(buf, "%s", "I am fd2\n");
    write(fd2, buf, strlen(buf));

    sprintf(buf, "%s", "I am fd3\n");
    write(fd3, buf, strlen(buf));

    fd_tmp = dup2(fd1, fd2);
    sprintf(buf, "%s fd1:%d, fd2:%d, fd_tmp:%d", "I am copy fd1\n", fd1, fd2, fd_tmp);
    write(fd_tmp, buf, strlen(buf));
    
    write(fd2, buf, strlen(buf));
    perror("write err");

    exit(0);
}
