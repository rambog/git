#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file> \n", argv[0]);
        return 0;
    }

    printf("i am guiyao\n");

    FILE *fp = NULL;
    fp = freopen(argv[1], "r+", stdout);
    
    printf("i am rambo\n");

    exit(0);
}
