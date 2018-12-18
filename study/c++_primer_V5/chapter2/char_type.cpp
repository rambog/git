/*======================================================================
*        filename: char_type.cpp
*        author: rambogui
*        data: 2018-12-18 08:35:27
======================================================================*/

#include <iostream>
#include <cstdio>

int main(int argc, char *argv[])
{
    char ch = 0xFF;
    unsigned char uch = 0xFF;
    signed char sch = 0xFF;

    std::printf("char:%d, uchar:%d, schar:%d\n", ch, uch, sch);

    return 0;
}
