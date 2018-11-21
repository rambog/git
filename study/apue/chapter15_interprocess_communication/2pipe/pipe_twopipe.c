#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <sys/select.h>

int
main(void)
{
    int ppfd1[2];
    int ppfd2[2];

    char foo[] = "qwertyuiasdfghjk";

    if (pipe(ppfd1) < 0) {
        perror("pipe fd1 err"); exit(0);
    }

    if (pipe(ppfd2) < 0) {
        perror("pipe fd2 err"); exit(0);
    }

    if (write(ppfd2[1], foo, strlen(foo)) != strlen(foo)) perror("write pipe err");

    fd_set readset;
    struct timeval to;
    int maxfd;
    maxfd = (ppfd1[0] > ppfd2[0] ? ppfd1[0] : ppfd2[0]) + 1;
    char buf[32];


    while (1) {
        FD_ZERO(&readset);
        FD_SET(ppfd1[0], &readset);
        FD_SET(ppfd2[0], &readset);
        to.tv_sec = 2;
        to.tv_usec = 0;

        if (select(maxfd, &readset, NULL, NULL, &to) > 0) {
            if (FD_ISSET(ppfd1[0], &readset)) {
                memset(buf, 0x00, sizeof(buf));
                read(ppfd1[0], buf, 8);
                printf("read from ppfd1 pipe : %s\n", buf);
            }

            if (FD_ISSET(ppfd2[0], &readset)) {
                memset(buf, 0x00, sizeof(buf));
                read(ppfd2[0], buf, 8);
                printf("read from ppfd2 pipe : %s\n", buf);
            }
        } else {
            break;
        }
    }
    
    return 0;
}
