/*======================================================================
*        filename: 7-36.cpp
*        author: rambogui
*        data: 2018-12-25 10:23:32
======================================================================*/

#include <iostream>

class X {
public:
    X(int i, int j) : base(i), rem(base%j) { }
    void show() const { std::cout << base << ' ' << rem << std::endl; }
private:
    int rem;
    int base;
};

int main(int argc, char *argv[])
{
    X a(5,2);
    a.show();
    return 0;
}
