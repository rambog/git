/*======================================================================
*        filename: arr_string_cstr.cpp
*        author: rambogui
*        data: 2018-12-19 19:13:05
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    const char *pch1;
    const char *pch2;

    std::string s("rambo");
    pch1 = s.c_str();
    s = "gambaaa";
    pch2 = s.c_str();

    std::cout << (void*)pch1 << ' ' << (void*)pch2 << std::endl;

    return 0;
}
