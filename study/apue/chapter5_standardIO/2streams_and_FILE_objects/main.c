#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 0;
    }

    FILE *f;
    f = fopen(argv[1], "r+");
    if (f == NULL) {
        printf("fopen %s err[%d] : %m\n", argv[1], errno);
        return 0;
    }

    int s_orient;

    errno = 0;
    s_orient = fwide(f, 3);
    if (errno != 0) {
        printf("fwide err[%d] : %m\n", errno);
    } else {
        printf("orient = %d\n", s_orient);
    }

    fputs("i am rambo\n", f);
    
    errno = 0;
    s_orient = fwide(f, -1);
    if (errno != 0) {
        printf("fwide err[%d] : %m\n", errno);
    } else {
        printf("orient after fputs = %d\n", s_orient);
    }

    exit(0);
}
