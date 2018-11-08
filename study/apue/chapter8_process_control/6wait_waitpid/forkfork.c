#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

int
main(void)
{
    pid_t pid;
    if ((pid = fork()) < 0)
        return 1;
    else if (pid == 0) {
        if ((pid = fork()) < 0)
            return 1;
        else if (pid > 0)
            exit(0);

        sleep(2);
        printf("second child, parent pid = %ld\n", (long)getppid());
        exit(0);
    }

    if (waitpid(pid, NULL, 0) != pid)
        perror("waitpid err");

    exit(0);
}
