#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int
main(int argc, char *argv[])
{
    pid_t pid;

    pid = vfork();
    if (pid == 0) {
        execlp(argv[1], "rambo", "argv1", "argv2", NULL);
        perror("execlp err");
        exit(0);
    }

    if (pid == waitpid(pid, NULL, 0))
        printf("waitpid %ld exit\n", (long)pid);
    else if (pid < 0)
        perror("waitpid err");

    return 0;
}
