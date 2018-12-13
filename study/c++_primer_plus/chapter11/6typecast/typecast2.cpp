/*======================================================================
*        filename: typecast2.cpp
*        author: rambogui
*        data: 2018-12-08 15:20:53
======================================================================*/

#include <iostream>

class foo
{
private:
    int n;
public:
    foo() {}
    foo(const int n1) { n = n1;}
    operator int() { return n; }
};

int main(int argc, char *argv[])
{
    foo f = 100;

    int tmp = f;

    std::cout << tmp << std::endl;

    return 0;
}
