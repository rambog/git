/*======================================================================
*        filename: 5-19.cpp
*        author: rambogui
*        data: 2018-12-20 22:33:00
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string str1, str2; 

    do {
        std::cin >> str1 >> str2;
    
        std::cout << (str1.size() > str2.size() ? str2 : str1) << std::endl;

    } while(1);

    return 0;
}
