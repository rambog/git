#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv)
{
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        perror("fork err");
        return 0;
    } else if (pid == 0) {
        for ( ; ; ) {
            sleep(1);
            printf("I am child : %ld\n", (long)getpid());
        }
    } else {
        if (wait(NULL) == -1) {
            perror("wait err");
            exit(0);
        }

        printf("I am parent : %ld\n", (long)getpid());
    }

    return 0;
}
