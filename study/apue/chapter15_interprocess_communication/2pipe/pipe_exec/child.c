#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>

int
main(int argc, char *argv[])
{
    int fd = atoi(argv[1]);
    char buf[] = "father, I am child\n";

    if (write(fd, buf, strlen(buf)) < 0) {
        perror("write pipe err\n");
    }

    return 0;
}
