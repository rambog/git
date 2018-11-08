#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int
main(void)
{
    int i;
    int (*main_addr)(void);

    main_addr = main;

    printf("main_addr : %p\n", main_addr);

    printf("environ addr : %p\n", environ);

    for (i = 0; environ[i] != NULL; i++)
        printf("env[%d] addr:%p content:%s\n", i, environ[i], environ[i]);

    return 0;
}
