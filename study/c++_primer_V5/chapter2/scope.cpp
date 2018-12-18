/*======================================================================
*        filename: scope.cpp
*        author: rambogui
*        data: 2018-12-18 11:07:00
======================================================================*/

#include <iostream>

int reused = 42;

int main(int argc, char *argv[])
{
    int unique = 0;

    std::cout << reused << " " << unique << std::endl;

    int reused = 0;

    std::cout << reused << " " << unique << std::endl;

    std::cout << ::reused << " " << unique << std::endl;

    return 0;
}
