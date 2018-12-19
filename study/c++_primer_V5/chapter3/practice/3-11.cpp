/*======================================================================
*        filename: 3-11.cpp
*        author: rambogui
*        data: 2018-12-19 10:33:52
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    const std::string s = "Keep out!";

    for (auto &c : s)
        std::cout << c;
    std::cout << std::endl;

    return 0;
}
