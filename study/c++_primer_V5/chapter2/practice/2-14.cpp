/*======================================================================
*        filename: 2-14.cpp
*        author: rambogui
*        data: 2018-12-18 11:11:08
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;

    std::cout << i << ' ' << sum << std::endl;

    return 0;
}
