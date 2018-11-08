#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage : %s <execfile>", argv[0]);
        return 0;
    }

    int fd = open("./tmpfile", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
    if (fd < 0) {
        perror("open err");
        return 0;
    }

#if 1
    int fdflag = fcntl(fd, F_GETFD);
    if (fdflag < 0) {
        perror("fcntl err");
        return 0;
    }
    fdflag |= FD_CLOEXEC;
    if (fcntl(fd, F_SETFD, fdflag) < 0) {
        perror("fcntl err");
        return 0;
    }
#endif

    char tmp[128];

    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork err");
        return 0;
    } else if (pid == 0) {
        char argvtmp[8];
        memset(argvtmp, 0x00, sizeof(argvtmp));
        sprintf(argvtmp,"%d", fd);
        execl(argv[1], argv[1], argvtmp, "tmpfile", NULL);
        perror("execl err");
    } else {
        memset(tmp, 0x00, sizeof(tmp));
        sprintf(tmp, "parent : %ld\n", (long)getpid());
        sleep(1);
        write(fd, tmp, strlen(tmp));
    }

    exit(0);
}
