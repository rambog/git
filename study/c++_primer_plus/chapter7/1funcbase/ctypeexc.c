/*======================================================================
*        filename: ctypeexc.c
*        author: rambogui
*        data: 2018-11-29 09:52:43
======================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int foo(int tmp)
{
    printf("%d\n", tmp);
}

int main(int argc, char *argv[])
{
    foo(2.0);
    return 0;
}
