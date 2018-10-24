#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 0;
    }

    FILE *fp = NULL;
    if ((fp = fopen(argv[1], "r+")) == NULL) {
        printf("fopen %s err[%d] : %m\n", argv[1], errno);
        return 0;
    }

    char buf1[16];
    char buf2[16];

    if (0 != setvbuf(fp, buf1, _IOLBF, sizeof(buf1))) {
        printf("setvbuf err[%d] : %m\n", errno);
        return 0;
    }

    memset(buf1, 0x00, sizeof(buf1));
    memset(buf2, 0x00, sizeof(buf2));

    char *str1 = "123456";

    fwrite(str1, 1, strlen(str1), fp);
    printf("buf1 : %s\n", buf1);

    exit(0);
}
