#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>

int
main(void)
{
    int pfd[2];
    pipe(pfd);

    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 == 0) {
        char foo[] = "I am first child\n";
        write(pfd[1], foo, strlen(foo));
        exit(0);
    }

    pid2 = fork();
    if (pid2 == 0) {
        char buf[64] = {0x00};
        read(pfd[0], buf, sizeof(buf));
        printf("child2 read str:%s", buf);
        exit(0);
    }

    wait(NULL);

    return 0;
}
