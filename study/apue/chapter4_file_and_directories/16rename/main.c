#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 3) {
        printf("usage : %s <dir1> <dir2>\n", argv[0]);
        return 1;
    }

    int sysret;
    sysret = rename(argv[1], argv[2]);
    if (sysret != 0) {
        printf("rename err : %m\n");
    }

    exit(0);
}
