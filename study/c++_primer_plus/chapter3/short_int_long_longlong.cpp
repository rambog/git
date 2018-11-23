/*======================================================================
*        filename: short_int_long_longlong.cpp
*        author: rambogui
*        data: 2018-11-23 09:05:50
======================================================================*/

#include <iostream>

int main()
{
    std::cout << "sizeof(short):" << sizeof(short) << std::endl;
    std::cout << "sizeof(int):" << sizeof(int) << std::endl;
    std::cout << "sizeof(long):" << sizeof(long) << std::endl;
    std::cout << "sizeof(long long):" << sizeof(long long) << std::endl;

    short tshort = ~0;
    int tint = ~0;
    long tlong = ~0;
    long long tlonglong = ~0;

    std::cout << tshort << " ";
    std::cout << tint << " ";
    std::cout << tlong << " ";
    std::cout << tlonglong << " ";
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "sizeof(unsigned short):" << sizeof(unsigned short) << std::endl;
    std::cout << "sizeof(unsigned int):" << sizeof(unsigned int) << std::endl;
    std::cout << "sizeof(unsigned long):" << sizeof(unsigned long) << std::endl;
    std::cout << "sizeof(unsigned long long):" << sizeof(unsigned long long) << std::endl;

    unsigned short tushort = ~0;
    unsigned int tuint = ~0;
    unsigned long tulong = ~0;
    unsigned long long tulonglong = ~0;

    std::cout << tushort << " ";
    std::cout << tuint << " ";
    std::cout << tulong << " ";
    std::cout << tulonglong << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}
