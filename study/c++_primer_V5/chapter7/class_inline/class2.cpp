/*======================================================================
*        filename: class2.cpp
*        author: rambogui
*        data: 2018-12-22 14:37:51
======================================================================*/

#include <iostream>

struct foo {
    int ret() const { return 2; }
    void foot();
};

static void f2()
{
    foo tmp;
    std::cout << "class" << tmp.ret() << std::endl;
}


void foo::foot()
{
    std::cout << "I am foot" << std::endl;
}
