/*======================================================================
*        filename: float_literal.cpp
*        author: rambogui
*        data: 2018-11-23 14:21:51
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    float f1 = 3.14;
    float f2 = 0.314e1;
    float f3 = 31.4e-1;
    int tmp = 0.314e1;
    std::cout << f1 << ' ' << f2 << ' ' << f3 << std::endl;
    std::cout << tmp << std::endl;
    return 0;
}
