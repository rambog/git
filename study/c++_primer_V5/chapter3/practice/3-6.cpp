/*======================================================================
*        filename: 3-6.cpp
*        author: rambogui
*        data: 2018-12-19 10:08:48
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string s; 

    getline(std::cin, s);

    for (auto &c : s)
        c = 'X';

    std::cout << s << std::endl;

    return 0;
}
