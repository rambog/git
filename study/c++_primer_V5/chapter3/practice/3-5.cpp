/*======================================================================
*        filename: 3-5.cpp
*        author: rambogui
*        data: 2018-12-19 09:34:58
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string temp, total; 

    while (std::cin >> temp)
        total += (temp + ' ');

    std::cout << total << std::endl;

    return 0;
}
