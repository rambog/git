/*======================================================================
*        filename: main.c
*        author: rambogui
*        data: 2018-12-03 16:18:48
======================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int foo();

int main(int argc, char *argv[])
{
    foo();
    return 0;
}

#if 0
int foo()
{
    printf("I am foo in main.cpp\n");
    return 0;
}
#endif
