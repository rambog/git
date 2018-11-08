#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int
main(void)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
        exit(7);

    if (wait(&status) == pid)
        pr_exit(status);


    pid = fork();
    if (pid == 0)
        abort();

    if (wait(&status) == pid)
        pr_exit(status);
    
    
    pid = fork();
    if (pid == 0)
        status /= 0;

    if (wait(&status) == pid)
        pr_exit(status);

    exit(0);
}
