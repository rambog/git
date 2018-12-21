/*======================================================================
*        filename: 6-4.cpp
*        author: rambogui
*        data: 2018-12-21 08:42:41
======================================================================*/

#include <iostream>

int fact(int val)
{
    int ret = 1;
    while (val >= 1)
        ret *= val--;
    return ret;
}

int main(int argc, char *argv[])
{
    unsigned n;

    while (std::cin >> n) {
        std::cout << n << "! is " << fact(n) << std::endl;
    }

    return 0;
}
