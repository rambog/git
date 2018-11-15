#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    char *tmp = "asdfghjk\n";
    int fd = open("tmp.txt", O_RDWR);

#if 0
    while (1)
    {
        write(fd, tmp, strlen(tmp));
    }
#else
    write(fd, tmp, strlen(tmp));
#endif

    exit(0);
}
