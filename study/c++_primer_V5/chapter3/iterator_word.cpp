/*======================================================================
*        filename: iterator_word.cpp
*        author: rambogui
*        data: 2018-12-19 14:33:23
======================================================================*/

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
    std::string s("rambo some string");
    std::cout << s << std::endl;

    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = toupper(*it);
    }

    std::cout << s << std::endl;

    return 0;
}
