/*======================================================================
*        filename: 6-25.cpp
*        author: rambogui
*        data: 2018-12-21 14:02:11
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string str;

    int idx = 0;
    while (idx != argc)
        str += argv[idx++];

    std::cout << str << std::endl;

    return 0;
}
