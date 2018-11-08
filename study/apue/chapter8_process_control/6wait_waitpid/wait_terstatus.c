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
        printf("i am abort child : %ld\n", (long)getpid());
        abort();
    }

    pid = fork();
    if (pid == 0) {
        printf("i am exit child : %ld\n", (long)getpid());
        exit(5);
    }

    pid_t pidend;

    int endstatus;
    while ((pidend = wait(&endstatus)) > 0) {
        if (WIFEXITED(endstatus)) {
            printf("parent wait child%ld normally exit:%d\n", (long)pidend, WEXITSTATUS(endstatus));
        }

        if (WIFSIGNALED(endstatus)) {
            printf("parent wait child%ld abnormally signal:%d\n", (long)pidend, WTERMSIG(endstatus));
        }
    }

    if (pidend < 0) perror("wait err");

    return 0;
}
