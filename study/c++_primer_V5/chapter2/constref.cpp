/*======================================================================
*        filename: constref.cpp
*        author: rambogui
*        data: 2018-12-18 16:05:54
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    double dval = 3.14;
    const int &ri = dval;

    std::cout << &ri << ' ' << &dval << std::endl;
    std::cout << dval << ' ' << ri << std::endl;

    dval = 6.28;
    std::cout << dval << ' ' << ri << std::endl;

    return 0;
}
