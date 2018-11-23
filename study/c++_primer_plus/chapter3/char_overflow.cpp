/*======================================================================
*        filename: char_overflow.cpp
*        author: rambogui
*        data: 2018-11-23 14:42:57
======================================================================*/

#include <iostream>
#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned char tmp;

    tmp = 0xffffff00 + 10;

    printf("tmp : %d\n", tmp);

    return 0;
}
