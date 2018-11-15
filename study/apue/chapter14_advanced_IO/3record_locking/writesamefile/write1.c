#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    char *tmp = "qwertyui\n";
    int fd = open("tmp.txt", O_RDWR);

    int fdstatus;
    fdstatus = fcntl(fd, F_GETFD);
    fdstatus |= FD_CLOEXEC;
    fcntl(fd, F_SETFD, fdstatus);

    pid_t pid;
    pid = vfork();
    if (pid == 0) {
        execl(argv[1], argv[1], NULL);
        perror("execl err");
        exit(0);
    }

#if 0
    while (1)
    {
        write(fd, tmp, strlen(tmp));
    }
#else
    sleep(1);
    write(fd, tmp, strlen(tmp));
#endif

    exit(0);
}
