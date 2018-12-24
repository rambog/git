/*======================================================================
*        filename: 7-14.cpp
*        author: rambogui
*        data: 2018-12-24 08:49:47
======================================================================*/

#include <iostream>

struct foo {
    int t = 11;
    foo() = default;
};

int main(int argc, char *argv[])
{
    foo f;
    std::cout << f.t << std::endl;
    return 0;
}
