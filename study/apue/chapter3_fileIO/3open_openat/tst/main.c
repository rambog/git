#include "apue.h"
#include <fcntl.h>

#define FILE_OPEN_MOD O_RDWR

int 
main(int argc, char *argv[])
{
    int fd_file = -1; 

    if (argc != 2)
        err_quit("usage %s <file>", argv[0]);        

    if ((fd_file = open(argv[1], FILE_OPEN_MOD)) < 0)
        err_sys("open file err");

    exit(0);
}
