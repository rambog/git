/*======================================================================
*        filename: 6-36.cpp
*        author: rambogui
*        data: 2018-12-21 16:22:10
======================================================================*/

#include <iostream>
#include <string>

std::string (&foo())[10]
{
    static std::string str[10] = {"rambo"};
    return str;
}

int main(int argc, char *argv[])
{
    std::cout << foo()[0] << std::endl; 
    return 0;
}
