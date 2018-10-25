#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFSIZE BUFSIZ
static char buf1[BUFSIZ];
static char buf2[BUFSIZ];

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 0;
    }

    printf("BUFSIZ : %u\n", BUFSIZ);

    FILE *fp = NULL;
    if ((fp = fopen(argv[1], "r+")) == NULL) {
        printf("fopen %s err[%d] : %m\n", argv[1], errno);
        return 0;
    }

    int fd = fileno(fp);
    if (fd < 0) {
        printf("fileno err : %m\n");
        return 0;
    }
    struct stat statbuf;
    if (fstat(fd, &statbuf) < 0) {
        printf("stat err : %m\n");
        return 0;
    }
    printf("print best blk : %u\n", statbuf.st_blksize);
    
    int ret = 1;
    if ((ret = setvbuf(fp, buf1, _IOLBF, sizeof(buf1))) != 0) {
        printf("setvbuf err[%d] : %m\n", errno);
        return 0;
    }
    printf("setvbuf ret : %d\n", ret);

    memset(buf1, 0x00, sizeof(buf1));
    memset(buf2, 0x00, sizeof(buf2));

    char *str1 = "1234";

    fwrite(str1, 1, strlen(str1), fp);
    printf("buf1 : %s\n", buf1);
    sprintf(buf1, "%s", "guiyao");

    char readbuf[16];
    int readn;
    memset(readbuf, 0x00, sizeof(readbuf));
#if 0
    rewind(fp);
    readn = fread(readbuf, 1, sizeof(readbuf), fp);
    if (readn <= 0) {
        printf("fread err : %m\n");
    }
    printf("readbuf : %s\n", readbuf);
#endif

    sprintf(buf2, "%s", "i am rambo");
    if ((ret = setvbuf(fp, buf2, _IOLBF, sizeof(buf2))) != 0) {
        printf("setvbuf err[%d] : %m\n", errno);
        return 0;
    }

    rewind(fp);
    readn = fread(readbuf, 1, sizeof(readbuf), fp);
    if (readn <= 0) {
        printf("fread err : %m\n");
    }
    printf("readbuf : %s\n", readbuf);

    memset(buf1, 0x00, sizeof(buf1));
    exit(0);
}
