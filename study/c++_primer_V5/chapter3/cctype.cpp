/*======================================================================
*        filename: cctype.cpp
*        author: rambogui
*        data: 2018-12-19 09:37:55
======================================================================*/

#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char *argv[])
{
    std::string temp;

    std::cin >> temp;

    for (int i = 0; i <= temp.size(); i++) {
        if (isxdigit(temp[i]))
            std::cout << temp[i];
    }
    std::cout << std::endl;
    std::cout << temp.size() << std::endl;

    return 0;
}
