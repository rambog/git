/*======================================================================
*        filename: unsigned_signed_type.cpp
*        author: rambogui
*        data: 2018-12-18 08:46:09
======================================================================*/

#include <iostream>
#include <cstdio>

int main(int argc, char *argv[])
{
    unsigned char c1 = -1;
    signed char c2 = 157;

    std::printf("c1:%d, c2:%d\n", c1, c2);

    //int f = 0x80000000;
    int f = 0xffffffff + 1;
    std::printf("int f:%d\n", f);

    unsigned int i1 = 0;
    int i2 = -42;
    i1 = i2;
    std::printf("int i1:%u\n", i1);

    return 0;
}
