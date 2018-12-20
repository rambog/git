/*======================================================================
*        filename: 4-6.cpp
*        author: rambogui
*        data: 2018-12-20 10:47:03
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int temp;
    std::cin >> temp;
    
    if (temp%2 == 0)
        std::cout << "even: " << temp << std::endl;
    else
        std::cout << "odd: " << temp << std::endl;

    return 0;
}
