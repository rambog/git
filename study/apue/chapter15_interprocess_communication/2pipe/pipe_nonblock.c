#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <sys/select.h>
#include <fcntl.h>
#include <time.h>

int
main(void)
{
    int ppfd[2];

    if (pipe(ppfd) < 0) {
        perror("pipe err");
        return 0;
    }

    int status = fcntl(ppfd[0], F_GETFL);
    status |= O_NONBLOCK;
    fcntl(ppfd[0], F_SETFL, status);

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        write(ppfd[1], "I am child", strlen("I am child"));
        sleep(1);
        exit(0);
    }

    char buf[16];
#if 0
    if (read(ppfd[0], buf, sizeof(buf)) < 0)
        perror("read pipe err");
#else
    fd_set readset;
    FD_ZERO(&readset);
    FD_SET(ppfd[0], &readset);
    struct timeval to;
    to.tv_sec = 2;
    to.tv_usec = 0;
    if (select(ppfd[0]+1, &readset, NULL, NULL, &to) > 0) {
        printf("read from pipe : %s\n", buf);
        printf("toval sec:%d usec:%ld\n", to.tv_sec, to.tv_usec);
    }
#endif

    waitpid(pid, NULL, 0);

    return 0;
}
