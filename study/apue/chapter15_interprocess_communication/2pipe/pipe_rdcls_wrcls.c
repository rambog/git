#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

void
sig_pipe(int signo)
{

}

int
main(void)
{
    printf("in rdcls wrcls tst\n");
    int ppfd1[2];
    int ppfd2[2];

    pipe(ppfd1);
    pipe(ppfd2);

    close(ppfd1[0]);
    dup(ppfd2[1]);
    close(ppfd2[1]);

    signal(SIGPIPE, sig_pipe);

    char tmpbuf[16];

    printf("read write\n");
    if (write(ppfd1[1], tmpbuf, sizeof(tmpbuf)) < 0) 
        perror("wirte pipe that close read err");

    if (read(ppfd2[0], tmpbuf, sizeof(tmpbuf)) < 0) 
        perror("read pipe that close write err");

    return 0;
}
