/*======================================================================
*        filename: throw.cpp
*        author: rambogui
*        data: 2018-12-20 22:55:29
======================================================================*/

#include <iostream>
#include <string>
#include <stdexcept>

int main(int argc, char *argv[])
{
    std::string str1, str2;

    std::cin >> str1 >> str2;

    if (str1 != str2)
        throw std::runtime_error("Data must refer to same ISBN");

    std::cout << str1 << str2 << std::endl;

    return 0;
}
