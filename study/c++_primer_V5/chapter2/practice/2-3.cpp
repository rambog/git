/*======================================================================
*        filename: 2-3.cpp
*        author: rambogui
*        data: 2018-12-18 09:28:38
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;

    return 0;
}
