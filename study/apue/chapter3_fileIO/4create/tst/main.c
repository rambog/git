#include "apue.h"
#include <fcntl.h>

#define FILE_OPEN_MOD O_RDONLY|O_TRUNC

int 
main(int argc, char *argv[])
{
    int fd_file = -1; 

    if (argc != 2)
        err_quit("usage %s <file>", argv[0]);        

    if ((fd_file = open(argv[1], FILE_OPEN_MOD)) < 0)
        err_sys("open file err");
    #if 0 
    fd_file = creat(argv[1], 777);
    
    write(fd_file, "rambo\n", sizeof("rambo\n"));

    char buf[128] = {0x00};
    ssize_t nread = read(fd_file, buf, sizeof(buf));
    if (nread < 0)
        err_sys("read err");
    else
        printf("read : %s\n");
    #endif

    exit(0);
}
