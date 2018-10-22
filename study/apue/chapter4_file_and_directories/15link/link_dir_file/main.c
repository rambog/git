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
        printf("usage : %s <file> <file>\n", argv[0]);
        return 1;
    }

    struct stat statbuf1;
    struct stat statbuf2;
    int sysret;

    sysret = stat(argv[1], &statbuf1);
    if (sysret < 0) {
        printf("stat err : %m\n");
        return 1;
    }

    sysret = stat(argv[2], &statbuf2);
    if (sysret < 0) {
        printf("stat err : %m\n");
        return 1;
    }

    printf("%s inode num : %u, %s inode num : %u\n", 
                argv[1], statbuf1.st_ino, argv[2], statbuf2.st_ino);

    char file1link[32];
    char file2link[32];

    memset(file1link, 0x00, sizeof(file1link));
    memset(file2link, 0x00, sizeof(file2link));

    sprintf(file1link, "%s%s", argv[1], "link");
    sprintf(file2link, "%s%s", argv[2], "link");

    unlink(file1link);
    unlink(file2link);

    if (access(file1link, F_OK) == 0)
        printf("%s exist!\n", file1link);
        
    if (access(file2link, F_OK) == 0)
        printf("%s exist!\n", file2link);

    sysret = link(argv[1], file1link);
    if (sysret < 0) {
        printf("link err : %m\n");
    }

    sysret = link(argv[2], file2link);
    if (sysret < 0) {
        printf("link err : %m\n");
    }

    sysret = stat(file1link, &statbuf1);
    if (sysret < 0) {
        printf("stat err : %m\n");
        return 1;
    }

    sysret = stat(file2link, &statbuf2);
    if (sysret < 0) {
        printf("stat err : %m\n");
        return 1;
    }

    printf("%s inode num : %u, %s inode num : %u\n", 
                file1link, statbuf1.st_ino, file2link, statbuf2.st_ino);

    exit(0);
}
