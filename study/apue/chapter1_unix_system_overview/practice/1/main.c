#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <dir>\n", argv[0]);
        return 0;
    }

    struct stat statbuf;

    if (stat(argv[1], &statbuf) != 0) {
        printf("stat err : %m\n");
        return 0;
    }

    if (!S_ISDIR(statbuf.st_mode)) {
        printf("cur target is not dir\n");
        return 0;
    }

    DIR *dir;
    struct dirent *dp;

    char path[128];

    if ((dir = opendir(argv[1])) == NULL) {
        printf("opendir err : %m\n");
        return 0;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            if (argv[1][strlen(argv[1])] == '/')
                sprintf(path, "%s%s", argv[1], dp->d_name);
            else
                sprintf(path, "%s/%s", argv[1], dp->d_name);

            if (stat(path, &statbuf) != 0) {
                printf("stat err : %m\n");
                continue;
            }

            printf("%s inode num:%u\n", dp->d_name, statbuf.st_ino);
        }
    }

    return 0;
}
