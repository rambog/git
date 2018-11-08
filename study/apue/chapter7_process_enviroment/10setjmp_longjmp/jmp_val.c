#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

int global;
jmp_buf jmpenv;

void foo1(int, int, int, int);
void foo2();

int
main(void)
{
    static int staval;
    volatile int volval;
    register int regval;
    auto int autval;

    global = 1; staval = 2; volval = 3; regval = 4; autval = 5;
    regval = 6; autval = 7;

    if (setjmp(jmpenv) != 0) {
        printf("after jmp : global:%d, staval:%d, volval:%d regval:%d autval:%d\n", global, staval, volval, regval, autval);
        exit(0);
    }

    global = 95; staval = 96; volval = 97; regval = 98; autval = 99;

    foo1(staval, volval, regval, autval);

    return 0;
}

void
foo1(int staval, int volval, int regval, int autval)
{
    printf("in foo1: global:%d, staval:%d, volval:%d regval:%d autval:%d\n", global, staval, volval, regval, autval);
    foo2();
}

void 
foo2()
{
    longjmp(jmpenv, 1);
}
