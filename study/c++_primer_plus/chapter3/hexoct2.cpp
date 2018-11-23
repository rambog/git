/*======================================================================
*        filename: hexoct2.cpp
*        author: rambogui
*        data: 2018-11-23 11:02:33
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int dec = 42;
    int hex = 42;
    int oct = 42;

    std::cout << "dec :" << dec << " (decimal for 42)" << std::endl;

    std::cout << std::hex;
    std::cout << "hex :" << hex << " (hexadecimal for 42)" << std::endl;

    std::cout << std::oct;
    std::cout << "oct :" << oct << " (octal for 42)" << std::endl;
    return 0;
}
