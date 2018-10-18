#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int
main(void)
{
    int fd;

/* hole */
    fd = creat("file.hole", 777);

    write(fd, buf1, 10);

    lseek(fd, 16384, SEEK_SET);

    write(fd, buf2, 10);

    lseek(fd, 100, SEEK_SET);
    
    int cyc = 1000;
    while(cyc-- > 0) {
        write(fd, buf2, 10);
    }
    
    close(fd);

/* nohole */
    fd = creat("file.nohole", 777);

    write(fd, buf1, 10);

    char buf[16374] = {0x00};
    write(fd, buf, 16374);

    write(fd, buf2, 10);

    close(fd);

    exit(0);
}
