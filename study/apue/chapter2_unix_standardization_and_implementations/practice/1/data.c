#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[], char *envp[])
{
    int tmp = 0x7FFFFFFF;

    printf("%d %u\n", tmp, tmp);

    tmp++;
    printf("%d %u\n", tmp, tmp);

    return 0;
}
