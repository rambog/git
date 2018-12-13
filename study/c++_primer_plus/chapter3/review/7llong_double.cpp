/*======================================================================
*        filename: 7llong_double.cpp
*        author: rambogui
*        data: 2018-11-24 09:23:22
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    unsigned long long llong = ~0;
    unsigned long long llong1 = ~0u;
    long long sllong = ~0;
    long long sllong1 = ~0u;

    double d1 = llong;

    std::cout << llong << std::endl;
    std::cout << llong1 << std::endl;
    std::cout << sllong << std::endl;
    std::cout << sllong1 << std::endl;
    std::cout << d1 << std::endl;
    std::cout << std::endl;

    unsigned long long ullong = ~0ull;
    signed long long sllong3 = ~0ll;

    std::cout << ullong << std::endl;
    std::cout << sllong3 << std::endl;

    return 0;
}
