/*======================================================================
*        filename: climits_max.cpp
*        author: rambogui
*        data: 2018-11-23 09:24:36
======================================================================*/

#include <iostream>
#include <climits>

int main()
{
    std::cout << "signed max:" << std::endl;
    std::cout << SHRT_MAX << std::endl;
    std::cout << INT_MAX << std::endl;
    std::cout << LONG_MAX << std::endl;
    std::cout << LLONG_MAX << std::endl;
    std::cout << "signed min:" << std::endl;
    std::cout << SHRT_MIN << std::endl;
    std::cout << INT_MIN << std::endl;
    std::cout << LONG_MIN << std::endl;
    std::cout << LLONG_MIN<< std::endl;
    std::cout << std::endl;

    std::cout << "unsigned max:" << std::endl;
    std::cout << USHRT_MAX << std::endl;
    std::cout << UINT_MAX << std::endl;
    std::cout << ULONG_MAX << std::endl;
    std::cout << ULLONG_MAX << std::endl;
    std::cout << "unsigned mix:" << std::endl;

    std::cout << "CHAR_BIT:" << CHAR_BIT << std::endl;
    return 0;
}
