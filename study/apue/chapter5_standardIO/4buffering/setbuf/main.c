#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int
main(int argc, char *argv[], char *envp)
{
    printf("BUFSIZ : %u\n", BUFSIZ);
    char buf1[8];
    char buf2[8];

    memset(buf1, 0x00, sizeof(buf1));
    memset(buf2, 0x00, sizeof(buf2));

    errno = 0;
    setbuf(stdout, buf1);
    if (errno != 0)
    {
        printf("setbuf err : %m\n");
    }

    char *out1 = "11111111111111111111111111111111111111111111111111111111111111111111111111111111";
    char *out2 = "22222222222222222222222222222222222222222222222222222222222222222222222222222222";

    while (*out1 != 0x00 && *out2 != 0x00) {
        fputc(*out1++, stderr);
        fputc(*out2++, stdout);
        usleep(200*1000);
    }

    printf("buf1 : %s\n", buf1);
    printf("buf2 : %s\n", buf2);

    sleep(5);

    exit(0);
}
