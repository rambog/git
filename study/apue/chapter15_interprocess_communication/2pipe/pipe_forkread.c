#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int 
main(void)
{
    int ppfd[2];
    if (pipe(ppfd) < 0) {
        perror("pipe err");
        return 0;
    }

    char buf[] = "qwertyuiasdfghjk";

    if (strlen(buf) != write(ppfd[1], buf, strlen(buf))) 
        perror("write pipe err");

    pid_t pid;
    pid = vfork();
    if (pid == 0) {
        char footmp[16] = {0x00};
        if (read(ppfd[0], footmp, 8) != 8) perror("read err");
        printf("child read str:%s\n", footmp);
        exit(0);
    }

    char footmp[16] = {0x00};
    if (read(ppfd[0], footmp, 8) != 8) perror("parent read err");
    printf("parent read str:%s\n", footmp);

    waitpid(pid, NULL, 0);

    exit(0);
}
