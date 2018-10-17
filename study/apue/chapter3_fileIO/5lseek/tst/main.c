#include "apue.h"
#include <fcntl.h>

#define FILE_OPEN_MOD O_RDWR|O_APPEND

int 
main(int argc, char *argv[])
{
    int fd_file = -1; 

    if (argc != 2)
        err_quit("usage %s <file>", argv[0]);        

    if ((fd_file = open(argv[1], FILE_OPEN_MOD)) < 0)
        err_sys("open file err");

    off_t cur = lseek(fd_file, 0, SEEK_CUR);
    printf("lseek cur position:%lu\n", cur);

    char buf[128];

    if (strlen("how are you, rambo\n") != read(fd_file, buf, strlen("how are you, rambo\n")))
        err_sys("read err");
    else
        printf("read :%s", buf);

    write(fd_file, "insert ramboguiyao\n", strlen("insert ramboguiyao\n"));

    cur = lseek(fd_file, 0, SEEK_CUR);
    printf("lseek cur position:%lu\n", cur);

    if (strlen("how are you, rambo\n") != read(fd_file, buf, strlen("how are you, rambo\n")))
        err_ret("read err");
    else
        printf("read :%s", buf);

    cur = lseek(fd_file, 0, SEEK_SET);
    printf("lseek cur position:%lu\n", cur);

    if (strlen("how are you, rambo\n") != read(fd_file, buf, strlen("how are you, rambo\n")))
        err_sys("read err");
    else
        printf("read :%s", buf);

    write(fd_file, "inseramboguiyao\n", strlen("inseramboguiyao\n"));
    

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
