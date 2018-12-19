/*======================================================================
*        filename: rang_for.cpp
*        author: rambogui
*        data: 2018-12-19 09:45:04
======================================================================*/

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
    std::string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;

    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;
    
    std::cout << punct_cnt
         << " punctuation characters in " << s << std::endl;
        
    return 0;
}
