#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define PATH_MAX_GUESS 1024

static char *path;
static size_t pathsize;

static char *
path_alloc(ssize_t *sizep)
{
    char *pathname = NULL;
#ifdef PATH_MAX
    *sizep = PATH_MAX;
#else
    *sizep = pathconf("/". _PC_PATH_MAX);
    if (*sizep < 0) {
        if (errno == 0)
            *sizep = PATH_MAX_GUESS;
        else {
            printf("pathconf err[%d] : %m\n", errno);
            exit(0);
        }
    } else {
        *sizep += 1;
    }
#endif

    if (pathname == NULL) {
        pathname = malloc(*sizep);
        if (pathname == NULL) {
            printf("malloc err[%d] : %m\n", errno);
            exit(0);
        }
    }

    return pathname;
}

static void
my_rmdir(char *pathname, char isdir)
{
    int sysret;
    struct stat statbuf;
    DIR *dp;
    struct dirent *dirp;
    int org;

    if (!isdir) {
        sysret = unlink(path);
        if (sysret < 0) {
            printf("%s unlink err[%d] : %m\n", pathname, errno);
            return;
        }
    } else {
        dp = opendir(path);
        if (dp == NULL) {
            printf("%s opendir err [%d] : %m\n", pathname, errno);
            return;
        }

        while ((dirp = readdir(dp)) != NULL) {
            if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) {
                continue;
            }

            org = strlen(path);
            path[org] = '/';
            path[org+1] = 0x00;
            memcpy(path+strlen(path), dirp->d_name, strlen(dirp->d_name));
            path[org+1+strlen(dirp->d_name)] = 0x00;

            sysret = stat(path, &statbuf);
            if (sysret < 0) {
                printf("%s stat err[%d] : %m\n", path, errno);
                continue;
            }
            my_rmdir(dirp->d_name, S_ISDIR(statbuf.st_mode));

            path[org] = 0x00;
        }
        closedir(dp);

        sysret = rmdir(path);
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

    path = path_alloc(&pathsize);
    if (*(argv[1]+strlen(argv[1])-1) == '/')
        memcpy(path, argv[1], strlen(argv[1])-1);
    else
        memcpy(path, argv[1], strlen(argv[1]));

    struct stat statbuf;
    if (stat(path, &statbuf) < 0) {
        printf("%s stat err[%d] : %m\n", argv[1], errno);
        return 0;
    }

    my_rmdir(path, S_ISDIR(statbuf.st_mode));

    exit(0);
}
