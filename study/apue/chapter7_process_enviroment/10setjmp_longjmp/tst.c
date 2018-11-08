#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>

int
main(void)
{
    jmp_buf jmpbuf;

    if (setjmp(jmpbuf) == 0);
    printf("first set jmp finish\n");
    sleep(1);

    if (setjmp(jmpbuf) == 0);
    printf("second set jmp finish\n");
    sleep(1);

    longjmp(jmpbuf, 1);

    printf("exit main\n");

    return 0;
}
