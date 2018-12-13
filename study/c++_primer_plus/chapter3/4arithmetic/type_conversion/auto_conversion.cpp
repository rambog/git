/*======================================================================
*        filename: auto_conversion.cpp
*        author: rambogui
*        data: 2018-11-24 08:34:53
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    short sht1 = 10;
    short sht2 = 10;
    char ch1 = 10;
    char ch2 = 10;
    bool bl1 = false;
    bool bl2 = true;

    std::cout << sizeof sht1 << " " << sizeof(short) << " " << sizeof(sht1+sht2) << std::endl;
    std::cout << sizeof ch1 << " " << sizeof(char) << " " << sizeof(ch1+ch2) << std::endl;
    std::cout << sizeof bl1 << " " << sizeof(bool) << " " << sizeof(bl1+bl2) << std::endl;
    std::cout << bl1 << " " << bl2 << std::endl;

    return 0;
}
