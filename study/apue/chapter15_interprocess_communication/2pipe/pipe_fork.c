#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int
main(void)
{
    char buf[128] = {0x00};
    int pipefd[2];

    if (0 != pipe(pipefd)) {
        perror("pipe err");
        return 0;
    }

    printf("src str:%s\n", buf);

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        FILE *fp = fdopen(pipefd[1], "w");
        if (fp == NULL) {
            perror("fdopen err");
            exit(0);
        }

        fprintf(fp, "hi parent, i am child");
        fflush(fp);
        _exit(0);
    }

    waitpid(pid, NULL, 0);

    if (write(pipefd[1], "\nI am parent", strlen("\nI am parent")) < 0)
        perror("write fd err");

    if (read(pipefd[0], buf, sizeof(buf)) < 0) {
        perror("read pipefd err");
        exit(0);
    } else {
        printf("read from pipe:%s\n", buf);
    }

    return 0;
}
