#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>

int globval = 6;
char buf[] = "a write to stdout\n";

int
main(void)
{
    int var;
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1) {
        perror("write err");
        return 0;
    }

    printf("before fork\n");

    if ((pid = fork()) < 0) {
        perror("fork error");
        return 0;
    } else if (pid == 0) {
        globval++;
        var++;
    } else {
        sleep(2);
    }
    
    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globval, var);

    return 0;
}
