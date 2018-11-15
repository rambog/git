#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int
main(void)
{
    int fd = open("tmp.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
    if (fd < 0) return 0;

    int fddup = dup(fd);
    if (fddup < 0) return 0;

    char *foo1 = "qwertyui\n";
    char *foo2 = "asdfghjk\n";

    write(fd, foo1, strlen(foo1));
    write(fddup, foo2, strlen(foo2));
    close(fddup);
    write(fd, foo1, strlen(foo1));

    return 0;
}
