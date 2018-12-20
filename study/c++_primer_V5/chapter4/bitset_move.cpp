/*======================================================================
*        filename: bitset_move.cpp
*        author: rambogui
*        data: 2018-12-20 14:27:36
======================================================================*/

#include <iostream>
#include <cstdio>

int main(int argc, char *argv[])
{
    unsigned char i = 0x01;
    unsigned int temp = 0;

    std::cout << sizeof(i << 42) << std::endl;

    temp = i << 10;
    i <<= 10;

    std::cout << temp << ' ' << i << std::endl;
    printf("%u %u\n", temp, i);

    return 0;
}
