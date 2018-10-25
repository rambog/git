#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file> \n", argv[0]);
        return 0;
    }

    FILE *fp;
    int fd;

    fp = fopen(argv[1], "r+");
    setvbuf(fp, NULL, _IOFBF, 0);

    char *buf1 = "i am rambo\n";
    char *buf2 = "i am guiyao\n";

    fwrite(buf1, sizeof(char), strlen(buf1), fp);

    fd = fileno(fp);

    write(fd, buf2, strlen(buf2));

    return 0;
}
