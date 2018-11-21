#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

static pid_t *childpid = NULL;

static int maxfd;

FILE*
my_popen(const char *cmdstring, const char *type)
{
    int i;
    int pfd[2];
    pid_t pid;
    FILE *fp;

    if ((type[0] != 'r' && tpye[0] != 'w') || type[1] != 0) {
        errno = EINVAL;
        return NULL;
    }

    if (childpid == NULL) {
    }
}
