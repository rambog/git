#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

int 
main(int argc, char *argv[], char *envp[])
{
    int fd = 5;

    if (-1 == dup2(fd, -2)) 
        printf("dup2 errno :%d errinfo :%m\n", errno); 

    struct stat statbuf;

    if (-1 == fstat(fd, &statbuf)) {
        printf("fstat errno :%d errinfo :%m\n", errno); 
    }

    return 0;
}
