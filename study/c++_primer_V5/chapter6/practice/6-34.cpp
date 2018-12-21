/*======================================================================
*        filename: 6-34.cpp
*        author: rambogui
*        data: 2018-12-21 16:00:46
======================================================================*/

#include <iostream>

int factorial(int val)
{
    if (val != 0)
        return factorial(val-1)*val;
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
