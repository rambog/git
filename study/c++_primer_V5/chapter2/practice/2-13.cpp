/*======================================================================
*        filename: 2-13.cpp
*        author: rambogui
*        data: 2018-12-18 11:10:12
======================================================================*/

#include <iostream>
int i = 42;

int main(int argc, char *argv[])
{
    int i = 100;
    int j = i;

    std::cout << j << std::endl;

    j = ::i;
    std::cout << j << std::endl;

    return 0;
}
