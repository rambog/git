#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage : %s <child.exec>\n", argv[0]);
        exit(0);
    }

    int ppfd[2];
    if (pipe(ppfd) < 0) {
        perror("pipe err");
        return 0;
    }

#if 0
    int status = fcntl(ppfd[1], F_GETFD);
    status |= FD_CLOEXEC;
    fcntl(ppfd[1], F_SETFD, status);
#endif

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        char tmp[12];
        sprintf(tmp, "%d", ppfd[1]);
        execl(argv[1], argv[1], tmp, NULL);
        perror("execl err\n");
        exit(0);
    }

    waitpid(pid, NULL, 0);

    char tmpbuf[64] = {0x00};

    if (read(ppfd[0], tmpbuf, sizeof(tmpbuf)) < 0)
        perror("read pipe err");

    printf("read from child : %s\n", tmpbuf);

    return 0;
}
