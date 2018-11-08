#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        printf("I am child : %ld\n", (long)getpid());
        exit(0);
    }


    sleep(2);

    if (pid == wait(NULL)) {
        printf("parent wait child : %ld\n", pid);
    } else {
        perror("wait err");
    }

    return 0;
}
