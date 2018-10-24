#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[], char *envp[])
{
    char *errout = "111111111111\n";
    char *outout = "222222222222\n";

    while (*errout != 0x00 && *outout != 0x00) {
        fputc(*errout++, stderr);
        fputc(*outout++, stdout);

        usleep(200*1000);
    }

    for ( ; ; ) {
        sleep(1);
    }

    exit(0);
}
