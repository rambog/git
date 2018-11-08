#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[], char *envp[])
{
    int i = 0;

    for (i = 0; argv[i] != NULL; i++) {
        printf("arg[%d] : %s\n", i, argv[i]);
    }

    printf("\n");

    for (i = 0; envp[i] != NULL; i++) {
        printf("env[%d] : %s\n", i, envp[i]);
    }

    return 0;
}
