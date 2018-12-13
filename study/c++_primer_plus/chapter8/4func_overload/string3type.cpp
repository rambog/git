/*======================================================================
*        filename: string3type.cpp
*        author: rambogui
*        data: 2018-12-01 10:33:01
======================================================================*/

#include <iostream>
#include <string>

void foo(const std::string *);

int main(int argc, char *argv[])
{
    foo("I am rambo");
    return 0;
}

void foo(const std::string *str)
{
    std::cout << *str << std::endl;
}
