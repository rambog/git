/*======================================================================
*        filename: class_const.cpp
*        author: rambogui
*        data: 2018-12-10 14:54:22
======================================================================*/

#include <iostream>

class foo
{
private:
    const int tmp;
public:
    //foo() {}
    foo(int n) : tmp(n) {}
    void show() { std::cout << tmp << std::endl; }
};

int main(int argc, char *argv[])
{
    foo f1(10);
    foo f2(123);

    f1.show();
    f2.show();

    return 0;
}
