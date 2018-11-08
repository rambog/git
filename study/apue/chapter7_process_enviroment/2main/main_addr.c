#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(void)
{
    int (*man_addr)(void);

    man_addr = main;

    printf("man_addr : %p\n", man_addr);

    return 0;
}
