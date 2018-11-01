#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 0;
    }

    int fd = open(argv[1], O_RDWR|O_CREAT, S_IRWXU);
    if (fd < 0) {
        printf("open %s err[%d] errstr : %m\n", argv[1], errno);
        return 0;
    }

    printf("%s fileno : %d\n", argv[1], fd);

    close(1);

    char err_buf[128];
    if (write(1, "write tst", 9) < 0) {
        sprintf(err_buf, "write err[%d] : %m\n", errno);
        write(2, err_buf, strlen(err_buf));
    }

    int fdb = dup(fd);
    if (fdb < 0) {
        printf("dup fd:%d err :%m\n", fd);
        return 0;
    } else {
        printf("dup fdb = %d\n", fdb);
    }

    sprintf(err_buf, "i am no buffer iofunction\n");
    write(1, err_buf, strlen(err_buf));

    //printf("\n");

    return 0;
}
