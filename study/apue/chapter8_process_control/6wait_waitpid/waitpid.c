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
        printf("I am child : %ld\n", (long)getpid());
        sleep(2);
        exit(3);
    }

    int status;
    pid_t endpid;

    endpid = waitpid(pid, &status, WNOHANG);
    if (pid != endpid)
        printf("pid : %ld %m\n", (long)endpid);

#if 0
    endpid = waitpid(pid, &status, 0);
    if (pid != endpid)
        perror("waitpid err");
    else 
        printf("wait pid : %ld\n", (long)endpid);
#endif

    while (1) pause();

    return 0;
}
