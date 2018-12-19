/*======================================================================
*        filename: init.cpp
*        author: rambogui
*        data: 2018-12-19 08:13:41
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i(10);
    int i2 {10.1};
    int i3 { 11 };

    std::cout << i << ' ' << i2 << ' ' << i3 << std::endl;

    return 0;
}
