/*======================================================================
*        filename: 2-17.cpp
*        author: rambogui
*        data: 2018-12-18 13:50:24
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i, &ri = i;

    i = 5; ri = 10;

    std::cout << i << " " << ri << std::endl;

    return 0;
}
