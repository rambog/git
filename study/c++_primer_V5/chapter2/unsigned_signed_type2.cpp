/*======================================================================
*        filename: unsigned_signed_type2.cpp
*        author: rambogui
*        data: 2018-12-18 09:19:29
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    unsigned u = 10;
    int i = 0x7fffffff;

    int result;

    result = u + i;

    std::cout << i + i << std::endl;
    std::cout << u + i << std::endl;
    std::cout << result << std::endl;

    return 0;
}
