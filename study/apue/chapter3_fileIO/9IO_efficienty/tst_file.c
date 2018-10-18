#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int
main(void)
{
    int fd;

    fd = open("tst.file", O_RDWR|O_CREAT|O_EXCL, 777);

    int cur = 4096;

    char buf[4096] = {0x99};

    while(cur-- > 0)
    {
        write(fd, buf, 4096);
    }
}
