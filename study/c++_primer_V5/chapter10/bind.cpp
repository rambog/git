/*======================================================================
*        filename: bind.cpp
*        author: rambogui
*        data: 2019-01-03 11:10:09
======================================================================*/

#include <iostream>
#include <functional>

using namespace std::placeholders;

void foo1(int i1, int i2, int i3, int i4, int i5)
{
    std::cout << "foo1: ";
    std::cout << i1 << ' ' << i2 << ' '
              << i3 << ' ' << i4 << ' '
              << i5 << std::endl;
}

void foo2(int i1, int i2)
{
    std::cout << "foo2: ";
    std::cout << i1 << ' ' << i2 << std::endl;
}

int main(int argc, char *argv[])
{
    int i1=1,i2=2,i3=3,i4=4,i5=5;

    foo1(i1,i2,i3,i4,i5);
    //foo1 = bind(foo2, _1, _2);
    auto foo = bind(foo1, _1, _2, i3, i4, i5);
    foo(1,2,100);
    //foo1(i1,i2,i3,i4,i5);

    return 0;
}
