#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int
main(void)
{
    int fd1 = open("tmp.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
    int fd2 = open("tmp.txt", O_RDWR|O_APPEND);

    char *foo1 = "qwertyui\n";
    char *foo2 = "asdfghjk\n";

    write(fd1, foo1, strlen(foo1));
    write(fd2, foo2, strlen(foo2));
    close(fd2);
    write(fd1, foo1, strlen(foo1));

    return 0;
}
