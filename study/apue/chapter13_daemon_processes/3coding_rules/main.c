#include "apue.h"
#include "daemonize.h"

int
main(int argc, char *argv[], char *envp[])
{
    daemonize(argv[1]);

    for ( ; ; )
        sleep(1);

    return 0;
}
