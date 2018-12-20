/*======================================================================
*        filename: 4-33.cpp
*        author: rambogui
*        data: 2018-12-20 15:28:06
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int v;
    int x = 5;
    int y = 10;

    v = (1 ? (++x, ++y) : (--x, --y));
    std::cout << v << std::endl;

    return 0;
}
