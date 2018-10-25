#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[1]);
        return 0;
    }

    printf("i am guiyao\n");

    fclose(stdout);
    stdout = fopen(argv[1], "w");
    if (stdout == NULL) {
        printf("fopen err : %m\n");
    }
    setvbuf(stdout, NULL, _IOLBF, 0);

    errno = 0;
    printf("i am rambo\n");
    if (errno != 0)
        perror("printf");

    exit(0);
}
