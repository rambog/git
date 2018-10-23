#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

static void
my_rmdir(char *pathname, char isdir)
{
    int sysret;
    struct stat statbuf;
    DIR *dp;
    struct dirent *dirp;

    if (!isdir) {
        sysret = unlink(pathname);
        if (sysret < 0) {
            printf("%s unlink err[%d] : %m\n", pathname, errno);
            return;
        }
    } else {
        dp = opendir(pathname);
        if (dp == NULL) {
            printf("%s opendir err [%d] : %m\n", pathname, errno);
            return;
        }

        while ((dirp = readdir(dp)) != NULL) {
            if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) {
                continue;
            }

            sysret = stat(dirp->d_name, &statbuf);
            if (sysret < 0) {
                printf("%s stat err[%d] : %m\n", dirp->d_name, errno);
                continue;
            }
            my_rmdir(dirp->d_name, S_ISDIR(statbuf.st_mode));
        }
        closedir(dp);

        sysret = rmdir(pathname);
        if (sysret < 0) {
            printf("rmdir %s err[%d] : %m\n", pathname, errno);
            return;
        }
    }
}

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <dir>\n", argv[0]);
        return 0;
    }

    struct stat statbuf;

    if (stat(argv[1], &statbuf) < 0) {
        printf("%s stat err[%d] : %m\n", argv[1], errno);
        return 0;
    }

    my_rmdir(argv[1], S_ISDIR(statbuf.st_mode));

    exit(0);
}
