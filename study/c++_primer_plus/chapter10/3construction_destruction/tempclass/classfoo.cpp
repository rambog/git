/*======================================================================
*        filename: classfoo.cpp
*        author: rambogui
*        data: 2018-12-06 08:24:27
======================================================================*/

#include <iostream>
#include "classfoo.h"

foo::foo()
{
    std::cout << "I am default construct" << std::endl;
}

foo::foo(const std::string &sname)
{
    name = sname; 
    std::cout << "your name: " << name << std::endl;
}

foo::~foo()
{
    std::cout << "I am destruct " << name << std::endl;
}
