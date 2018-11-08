#include <stdio.h>

int
main(int argc, char *argv[], char *envp[])
{
    int i;

    for (i = 0; envp[i] != NULL; i++)
        printf("env[%d] addr:%p, content:%s\n", i, envp[i], envp[i]);

    return 0;
}
