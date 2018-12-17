/*======================================================================
*        filename: 1-12forsum.cpp
*        author: rambogui
*        data: 2018-12-17 13:52:53
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int sum = 0;

    for (int i = -100; i <= 100; ++i)
        sum += i;

    std::cout << "sum of inclusive -100 to 100: ";
    std::cout << sum << std::endl;

    return 0;
}
