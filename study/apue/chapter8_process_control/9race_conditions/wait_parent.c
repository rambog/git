#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>

int
main(void)
{
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        while (pid != 1) {
            pid = getppid();
            printf("child :%ld, parent:%ld\n", (long)getpid(), (long)pid);
            usleep(200*1000);
        }

        exit(0);
    }

    sleep(2);

    printf("parent quit\n");
    exit(0);
}
