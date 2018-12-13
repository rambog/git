/*======================================================================
*        filename: class_staticconst2.cpp
*        author: rambogui
*        data: 2018-12-10 14:52:47
======================================================================*/

#include <iostream>

class foo
{
private:
    static int tmp;
public:
    void show() const { std::cout << tmp << std::endl; }
};

int foo::tmp = 123;

int main(int argc, char *argv[])
{
    foo f;
    f.show();
    return 0;
}
