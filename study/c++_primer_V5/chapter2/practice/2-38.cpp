/*======================================================================
*        filename: 2-38.cpp
*        author: rambogui
*        data: 2018-12-19 08:01:21
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 0;
    double d = 0;

    auto a1 = i+d;
    decltype(i + d) d1;

    std::cout << sizeof a1 << ' ' << sizeof d1 << std::endl;

    return 0;
}
