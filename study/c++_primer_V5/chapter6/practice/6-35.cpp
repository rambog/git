/*======================================================================
*        filename: 6-35.cpp
*        author: rambogui
*        data: 2018-12-21 16:02:58
======================================================================*/

#include <iostream>

int factorial(int val)
{
    if (val > 1)
        return factorial(val--) * val;
    return 1;
}

int main(int argc, char *argv[])
{
    unsigned tmp;

    while (std::cin >> tmp) {
        std::cout << factorial(tmp) << std::endl;
    }

    return 0;
}
