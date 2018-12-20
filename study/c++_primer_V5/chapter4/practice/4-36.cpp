/*======================================================================
*        filename: 4-36.cpp
*        author: rambogui
*        data: 2018-12-20 16:32:21
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 2;
    double d = 6.5;

    i *= d;
    std::cout << i << ' ';
    i = 2; d = 6.5;
    std::cout << i*d << std::endl;

    i = 2; d = 6.5;
    i *= static_cast<int>(d);
    std::cout << i << std::endl;

    return 0;
}
