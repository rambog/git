#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
#define RWXRWXRWX (S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH)

int
main(void)
{
    creat("ori", RWXRWXRWX);

    umask(0);

    if (creat("foo", RWRWRW) < 0)
        return 0;

    umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);

    if (creat("bar", RWRWRW) < 0)
        return 0;

    exit(0);
}
