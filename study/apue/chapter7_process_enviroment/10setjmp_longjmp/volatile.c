#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <unistd.h>
#include <setjmp.h>

jmp_buf jmpbuf;

int
main(void)
{
    volatile int volval;
    register int regval;

    volval = 1; regval = 2;

    if (setjmp(jmpbuf) != 0) {
        printf("volval : %d, regval : %d\n", volval, regval);
        return 0;
    }

    volval = 99;
    regval = 98;

    longjmp(jmpbuf, 1);

    return 0;
}
