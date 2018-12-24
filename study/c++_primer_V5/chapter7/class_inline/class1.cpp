/*======================================================================
*        filename: class1.cpp
*        author: rambogui
*        data: 2018-12-22 14:37:51
======================================================================*/

#include <iostream>

struct foo {
    int ret() const { return 1; }
    void foot();
};

void f1 ()
{
    foo tmp;
    std::cout << "class" << tmp.ret() << std::endl;
}

void f2();

int main()
{
    //f1();
    //f2();
    foo tmp;
    tmp.foot();
}

void foo::foot()
{
    std::cout << "I am foot again" << std::endl;
}
