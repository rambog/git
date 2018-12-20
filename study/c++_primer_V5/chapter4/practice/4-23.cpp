/*======================================================================
*        filename: 4-23.cpp
*        author: rambogui
*        data: 2018-12-20 14:17:38
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string s = "word";
    std::string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
    std::cout << p1 << std::endl;
    return 0;
}
