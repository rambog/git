/*======================================================================
*        filename: shorterString.cpp
*        author: rambogui
*        data: 2018-12-21 14:34:04
======================================================================*/

#include <iostream>
#include <string>
using std::string;

string &shorterString(const string &s1, const string &s2)
{
    static string str;
    return s1.size() <= s2.size() ? str:str;
}

int main(int argc, char *argv[])
{

    return 0;
}
