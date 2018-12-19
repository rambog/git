/*======================================================================
*        filename: 3-4_2.cpp
*        author: rambogui
*        data: 2018-12-19 09:32:59
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string temp1, temp2; 

    while (std::cin >> temp1 >> temp2)
        std::cout << (temp1.size() > temp2.size() ? temp1 : temp2) << std::endl;

    return 0;
}
