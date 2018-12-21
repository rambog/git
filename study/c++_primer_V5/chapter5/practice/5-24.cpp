/*======================================================================
*        filename: 5-24.cpp
*        author: rambogui
*        data: 2018-12-21 08:19:08
======================================================================*/

#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[])
{
    double d1, d2;

    while (std::cin >> d1 >> d2) {
        if (d2 == 0)
            throw std::runtime_error("d2 == 0");
        std::cout << d1/d2 << std::endl;
    }

    return 0;
}
