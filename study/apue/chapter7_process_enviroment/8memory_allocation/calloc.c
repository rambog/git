#include <stdio.h>
#include <stdlib.h>

#define CALLOCSIZE 8 

int
main(int argc, char *argv[])
{
    unsigned char *ptmp;

    ptmp = (unsigned char *)calloc(4, CALLOCSIZE);
    if (ptmp == NULL)
        printf("calloc err\n");

    int i = 0;
    for (i = 0; i < CALLOCSIZE; i++)
        printf("%#02x ", ptmp[i]);
    printf("\n");

    return 0;
}
