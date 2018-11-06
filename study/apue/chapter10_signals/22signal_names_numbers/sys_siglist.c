#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>

//extern char *const sys_siglist[];

int
main(int argc, char *argv[])
{
    int i = 0;

    for (i = 1; sys_siglist[i] != NULL; i++) {
        printf("signo : %d  name:%s\n", sys_siglist[i], i);
    }

    return 0;
}
