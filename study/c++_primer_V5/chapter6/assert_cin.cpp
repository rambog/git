/*======================================================================
*        filename: assert_cin.cpp
*        author: rambogui
*        data: 2018-12-22 14:17:08
======================================================================*/

#include <iostream>
#include <string>
#include <cassert>

int main(int argc, char *argv[])
{
    int str;

    std::cin >> str;
    assert(std::cin);
    return 0;
}
