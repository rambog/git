/*======================================================================
*        filename: ifelse.cpp
*        author: rambogui
*        data: 2018-11-28 08:25:18
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    char ch;

    std::cout << "Type, and I shall repeat.\n";
    std::cin.get(ch);
    while (ch != '.')
    {
        if (ch == '\n')
            std::cout << ch;
        else
            std::cout << ++ch;

        std::cin.get(ch);
    }

    std::cout << "\nPlease excuse the slight confusion.\n";

    return 0;
}
