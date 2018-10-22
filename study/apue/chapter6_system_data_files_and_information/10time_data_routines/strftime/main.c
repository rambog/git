#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(void)
{
    time_t t;
    struct tm *tmp;

    char buf1[16];
    char buf2[64];
    char buf3[16];
    char buf4[64];

    time(&t);
    tmp = localtime(&t);
    if (strftime(buf1, sizeof(buf1), "time and date: %r, %a %b %d, %Y", tmp) == 0)
        printf("buffer length %d is too samall\n", sizeof(buf1));
    else
        printf("%s\n", buf1);
    if (strftime(buf2, sizeof(buf2), "time and date: %r, %a %b %d, %Y", tmp)== 0)
        printf("buffer length %d is too samall\n", sizeof(buf2));
    else
        printf("%s\n", buf2);


    tmp = gmtime(&t);
    if (strftime(buf3, sizeof(buf3), "time and date: %r, %a %b %d, %Y", tmp)== 0)
        printf("buffer length %d is too samall\n", sizeof(buf3));
    else
        printf("%s\n", buf3);
    if (strftime(buf4, sizeof(buf4), "time and date: %r, %a %b %d, %Y", tmp) == 0)
        printf("buffer length %d is too samall\n", sizeof(buf4));
    else
        printf("%s\n", buf4);

    exit(0);
}
