#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int
main(void)
{
    struct stat statbuf;

    if (stat("foo", &statbuf) < 0)
        return -1;

    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
        return -1;


    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
        return -1;

    exit(0);
}
