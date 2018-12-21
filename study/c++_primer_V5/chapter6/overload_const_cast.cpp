/*======================================================================
*        filename: overload_const_cast.cpp
*        author: rambogui
*        data: 2018-12-21 16:46:23
======================================================================*/

#include <iostream>
#include <string>
using std::string;

const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;   
}

string &shorterString(string &s1, string &s2)
{
    return const_cast<string &>(shorterString(
                        const_cast<const string&>(s1),const_cast<const string&>(s2)));
    //return shorterString(s1, s2);
}

int main(int argc, char *argv[])
{
    string str1 = "rambo", str2 = "guiyao";

    std::cout << shorterString(str1, str2) << std::endl;

    return 0;
}
