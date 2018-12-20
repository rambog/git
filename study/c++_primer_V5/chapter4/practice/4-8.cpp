/*======================================================================
*        filename: 4-8.cpp
*        author: rambogui
*        data: 2018-12-20 11:23:25
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 0;
    std::cout << (i == i++) << ' ' << i << std::endl;

    i = 0;
    std::cout << (i == ++i) << ' ' << i << std::endl;
    return 0;
}
