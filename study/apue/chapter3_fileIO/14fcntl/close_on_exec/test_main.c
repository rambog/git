#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage : %s <fd>\n", argv[0]);
        return 1;
    }

    int fd = atoi(argv[1]);
    printf("get fd %d\n", fd);

    int nwr;
    char buf[16];
    sprintf(buf, "%s", "I am fork\n");
    for ( ; ; ) {
       nwr = write(fd, buf, strlen(buf)); 
       if (nwr < 0) {
           perror("fork write err");
           return 1;
       }
       sleep(1);
    }

    exit(0);
}
