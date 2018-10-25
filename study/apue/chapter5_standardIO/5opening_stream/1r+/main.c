#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[1]);
        return 0;
    }

    FILE *fp = fopen(argv[1], "r+"); 
    if (fp == NULL) {
        printf("%s fopen err[%d] : %m\n", argv[1], errno);
        return 0;
    }

    int nwrite, nread;
    char buf[64];
    off_t pos;

#if 1
    pos = ftello(fp);
    printf("before write pos : %u\n", pos);
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "i am rambo\n", strlen(buf));
    errno = 0;
    if ((nwrite = fwrite(buf, sizeof(char), strlen(buf), fp)) != strlen(buf)) {
        printf("%s fwrite err[%d] : %m\n", argv[1], nwrite);
    }
#endif

    pos = ftello(fp);
    printf("before read pos : %u\n", pos);
    //memset(buf, 0x00, sizeof(buf));
    errno = 0;
    fseek(fp, 0, SEEK_SET);
    if ((nread = fread(buf, sizeof(char), strlen(buf), fp)) <= 0) {
        printf("%s fread err[%d] : %m\n", argv[1], nread);
        if (ferror(fp))
            printf("fread err \n");
        if (feof(fp))
            printf("fread end\n");
    }
    printf("buf fread : %s\n", buf);

    errno = 0;
    if ((nwrite = fwrite(buf, sizeof(char), strlen(buf), fp)) != strlen(buf)) {
        printf("%s fwrite err[%d] : %m\n", argv[1], nwrite);
    }   

    if ((nread = fread(buf, sizeof(char), strlen(buf), fp)) <= 0) {
        printf("%s fread err[%d] : %m\n", argv[1], nread);
        if (ferror(fp))
            printf("fread err \n");
        if (feof(fp))
            printf("fread end\n");
    }

    pos = ftello(fp);
    printf("after read/write pos : %u\n", pos);

    exit(0);
}
