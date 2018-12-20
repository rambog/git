/*======================================================================
*        filename: sizeof.cpp
*        author: rambogui
*        data: 2018-12-20 14:57:00
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int *pi;
    double *pd;
    long double *pld;

    std::cout << sizeof pi << ' ' << sizeof pd << ' ' << sizeof pld << std::endl;
    std::cout << sizeof *pi << ' ' << sizeof *pd << ' ' << sizeof *pld << std::endl;

    return 0;
}
