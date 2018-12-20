/*======================================================================
*        filename: 4-13.cpp
*        author: rambogui
*        data: 2018-12-20 13:18:57
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i;
    double d;

    d = i = 3.5;
    std::cout << d << ' ' << i << std::endl;
    i = d = 3.5;
    std::cout << d << ' ' << i << std::endl;

    return 0;
}
