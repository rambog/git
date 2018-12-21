/*======================================================================
*        filename: 5-25.cpp
*        author: rambogui
*        data: 2018-12-21 08:21:41
======================================================================*/

#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[])
{
    double d1, d2;

    while (std::cin >> d1 >> d2) {
        try {
            if (d2 == 0)
                throw std::runtime_error("d2 == 0");
        } catch (std::runtime_error err) {
            std::cout << err.what();
            char ch;
            std::cout << "Please enter d2 agian?" << std::endl;
            std::cout << "y or n: ";
            if (!(std::cin >> ch) || ch == 'n')
                break;
            std::cin >> d2;
        }

        std::cout << "d1/d2 = " << d1/d2 << std::endl;
    }

    return 0;
}
