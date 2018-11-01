#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[], char *envp[])
{
    time_t tn;
    struct tm tmn;

    time(&tn);
    gmtime_r(&tn, &tmn);

    char buf[4];

    memset(buf, 0x00, sizeof(buf));
    ctime_r(&tn, buf);
    printf("ctime : %s\n", buf);

    memset(buf, 0x00, sizeof(buf));
    asctime_r(&tmn, buf);
    printf("asctime : %s\n", buf);

    return 0;
}
