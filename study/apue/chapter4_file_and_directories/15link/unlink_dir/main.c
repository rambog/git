#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : % <dir>", argv[0]);
        return 1;
    }

    int sysret;
    
    sysret = unlink(argv[1]);
    if (sysret < 0) {
        printf("unlink err : %m\n");
        return 1;
    }

    exit(0);
}
