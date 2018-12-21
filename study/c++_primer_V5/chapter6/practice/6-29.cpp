/*======================================================================
*        filename: 6-29.cpp
*        author: rambogui
*        data: 2018-12-21 14:22:01
======================================================================*/

#include <iostream>
#include <initializer_list>
#include <string>

void err_msg(/*const*/ std::initializer_list<std::string> &il)
{
    for (std::initializer_list<std::string>::const_iterator citer = il.begin();
            citer != il.end(); ++citer)
        std::cout << *citer << ' ';
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    err_msg({"rambo", "guiyao"});
    return 0;
}
