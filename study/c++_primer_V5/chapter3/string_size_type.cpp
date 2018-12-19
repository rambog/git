/*======================================================================
*        filename: string_size_type.cpp
*        author: rambogui
*        data: 2018-12-19 09:15:43
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::cout << sizeof(std::string::size_type) << std::endl;
    std::string str("rambo");

    int tmp = -10;

    std::cout << tmp + str.size() << std::endl;
    std::cout << tmp * str.size() << std::endl;

    return 0;
}
