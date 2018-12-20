/*======================================================================
*        filename: try.cpp
*        author: rambogui
*        data: 2018-12-20 23:01:10
======================================================================*/

#include <iostream>
#include <string>
#include <stdexcept>

int main(int argc, char *argv[])
{
    std::string str1, str2;

    while (std::cin >> str1 >> str2) {
        try {
            if (str1 != str2)
                throw std::runtime_error("Data must refer to same ISBN");
        } catch (std::runtime_error err) {
            std::cout << err.what()
                 << "\nTry Again? Enter y or n" << std::endl;
            char c;
            std::cin >> c;
            if (!std::cin || c == 'n')
                break;
        }
    }

    return 0;
}
