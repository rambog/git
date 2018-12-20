/*======================================================================
*        filename: 5-20.cpp
*        author: rambogui
*        data: 2018-12-20 22:37:40
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::string first;
    std::string second;

    while (std::cin >> first) {
        if (second != first)
            second = first;
        else
            break;
    }

    return 0;
}
