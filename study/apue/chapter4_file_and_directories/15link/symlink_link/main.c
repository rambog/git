#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int 
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <symfile>\n", argv[0]);
        return 1;
    }

    char symlink[32];
    char orglink[32];

    sprintf(symlink, "%s%s", argv[1], "_symlink");
    sprintf(orglink, "%s%s", argv[1], "_orglink");

    int sysret;
    sysret = linkat(AT_FDCWD, argv[1], AT_FDCWD, symlink, 0);
    if (sysret < 0) {
        printf("linkat err : %m\n");
        return 1;
    }
    sysret = linkat(AT_FDCWD, argv[1], AT_FDCWD, orglink, AT_SYMLINK_FOLLOW);
    if (sysret < 0) {
        printf("linkat err : %m\n");
        return 1;
    }

    exit(0);
}
