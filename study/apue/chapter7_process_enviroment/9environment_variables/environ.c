#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int
main(int argc, char *argv[], char *envp[])
{
    int i;
    printf("environ addr : %p\n", environ);

    for (i = 0; envp[i] != NULL; i++)
        printf("env[%d] : %s\n", i, envp[i]);

    setenv("gyao", "guiyao", 1);
    printf("environ addr : %p\n", environ);

    return 0;
}
