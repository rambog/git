/*======================================================================
*        filename: class_staticconst.cpp
*        author: rambogui
*        data: 2018-12-10 14:50:36
======================================================================*/

#include <iostream>

class foo
{
private:
    static const int num;
public:
    void show() { std::cout << num << std::endl; }
};

const int foo::num = 100;

int main(int argc, char *argv[])
{
    foo f;

    f.show();

    return 0;
}
