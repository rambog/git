/*======================================================================
*        filename: initializer_list.cpp
*        author: rambogui
*        data: 2018-12-21 14:12:10
======================================================================*/

#include <iostream>
#include <initializer_list>
#include <string>

void error_msg(std::initializer_list<std::string> il)
{
    for (std::initializer_list<std::string>::iterator iter = il.begin();
            iter != il.end(); ++iter)
        std::cout << *iter << ' ';
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    error_msg({"rambo", "guiyao", "hello"});
    return 0;
}
