/*======================================================================
*        filename: funcret_lr.cpp
*        author: rambogui
*        data: 2018-12-21 14:40:48
======================================================================*/

#include <iostream>
#include <string>
using std::string;

string &foo()
{
    static string str = "rambo";
    std::cout << str << std::endl;
    return str;
}

int main(int argc, char *argv[])
{
    foo() = "guiyao";
    foo();
    return 0;
}
