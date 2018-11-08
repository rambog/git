#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

int
main(void)
{
    int fd = open("./tmpfile", O_RDWR|O_CREAT|O_EXCL|O_TRUNC, S_IRWXU);
    if (fd < 0) {
        perror("open err");
        return 0;
    }

    char tmp[128];

    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork err");
        return 0;
    } else if (pid == 0) {
        memset(tmp, 0x00, sizeof(tmp));
        sprintf(tmp, "child : %ld\n", (long)getpid());
        sleep(2);
        write(fd, tmp, strlen(tmp));
    } else {
        memset(tmp, 0x00, sizeof(tmp));
        sprintf(tmp, "child : %ld\n", (long)getpid());
        sleep(1);
        write(fd, tmp, strlen(tmp));
    }

    exit(0);
}
