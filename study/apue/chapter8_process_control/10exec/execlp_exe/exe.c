#include <stdio.h>

int 
main(int argc, char *argv[])
{
    int i = 0;
    for (i = 0; argv[i] != NULL; i++) {
        printf("argv[%d] : %s\n", i, argv[i]);
    }

    return 0;
}
