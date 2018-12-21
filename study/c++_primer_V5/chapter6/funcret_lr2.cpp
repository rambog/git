/*======================================================================
*        filename: funcret_lr2.cpp
*        author: rambogui
*        data: 2018-12-21 14:42:59
======================================================================*/

#include <iostream>
#include <string>
using std::string;

char &get_val(string &str, string::size_type ix)
{
    return str[ix];
}

int main(int argc, char *argv[])
{
    string s("rambo");
    std::cout << s << std::endl;
    get_val(s, 0) = 'A';
    std::cout << s << std::endl;
    return 0;
}
