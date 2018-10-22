#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char *argv[], char *envp)
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 1;
    }

    int sysret;
    char newsym[32];
    memset(newsym, 0x00, sizeof(newsym));
    sprintf(newsym, "%s%s", argv[1], "_sym");

    sysret = symlink(argv[1], newsym);
    if (sysret != 0) {
        printf("symlink err : %m\n");
        return 1;
    }

    exit(0);
}
