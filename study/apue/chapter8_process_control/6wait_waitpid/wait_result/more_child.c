#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    pid_t pidchild, pidwait;

    pidchild = fork();
    if (pidchild == 0) {
        printf("I am child : %ld\n", (long)getpid());

        sleep(4);

        exit(0);
    }

    pidchild = fork();
    if (pidchild == 0) {
        printf("I am child : %ld\n", (long)getpid());

        sleep(2);

        exit(0);
    }

    while ((pidwait = wait(NULL)) > 0) {
        printf("parent get child%ld exit\n", (long)pidwait);
    }

    if (pidwait < 0) perror("wait err");

    return 0;
}
