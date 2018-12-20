/*======================================================================
*        filename: bitset_move2.cpp
*        author: rambogui
*        data: 2018-12-20 14:31:33
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 0x80000000;

    std::cout << i << std::endl;
    std::cout << (i >> 31) << std::endl;
    std::cout << (i >> 32) << std::endl;
    std::cout << (i >> 33) << std::endl;

    return 0;
}
