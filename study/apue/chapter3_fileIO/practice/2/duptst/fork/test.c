#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>

int 
main(int argc, char *argv[])
{
    int fdo, fdb;

    fdo = atoi(argv[1]);
    fdb = atoi(argv[2]);

    printf("exec fdo : %d, fdb : %d\n", fdo, fdb);

    char buftmp[128];

    memset(buftmp, 0x00, sizeof(buftmp));
    sprintf(buftmp, "execl proc i am fdo\n");
    if (write(fdo, buftmp, strlen(buftmp)) < 0) {
        printf("write err[%d], %m\n", errno);
    }

    memset(buftmp, 0x00, sizeof(buftmp));
    sprintf(buftmp, "execl proc i am fdb\n");
    if (write(fdb, buftmp, strlen(buftmp)) < 0) {
        printf("write err[%d], %m\n", errno);
    }

    return 0;
}
