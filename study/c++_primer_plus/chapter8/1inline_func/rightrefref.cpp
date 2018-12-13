/*======================================================================
*        filename: rightrefref.cpp
*        author: rambogui
*        data: 2018-11-30 13:40:59
======================================================================*/

#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
    double &&rref = std::sqrt(36.00);
    double j = 15.0;
    double &&jref = 2.0*j + 18.5;
    std::cout << rref << std::endl;
    std::cout << jref << std::endl;
    return 0;
}
