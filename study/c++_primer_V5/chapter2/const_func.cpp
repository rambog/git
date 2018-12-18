/*======================================================================
*        filename: const_func.cpp
*        author: rambogui
*        data: 2018-12-18 16:38:02
======================================================================*/

#include <iostream>
#include <cmath>
#include <cstdlib>

int read(int i)
{
    return i;
}

int main(int argc, char *argv[])
{
    //const int sz = std::atoi(argv[1]);
    const int sz = read(atoi(argv[1]));

    char buff[sz];
    std::cout << sizeof buff << std::endl;

    char buff2[read(atoi(argv[1]))];
    std::cout << sizeof buff2 << std::endl;

    return 0;
}
