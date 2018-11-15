#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int
main(void)
{
    int fd = open("tmp.txt", O_RDWR|O_CREAT|O_EXCL, S_IRWXU);
    if (fd < 0) return 0;

    int status;
    status = fcntl(fd, F_GETFL);
    status |= O_NONBLOCK;
    fcntl(fd, F_SETFL, status);

    char tmp[128];
    memset(tmp, 0x00, sizeof(tmp));
    sprintf(tmp, "%s", "i am rambo");

    if (strlen(tmp) != write(fd, tmp, strlen(tmp)))
        perror("write err");

    return 0;
}
