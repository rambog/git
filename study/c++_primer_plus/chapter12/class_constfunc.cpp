/*======================================================================
*        filename: class_constfunc.cpp
*        author: rambogui
*        data: 2018-12-10 09:32:11
======================================================================*/

#include <iostream>

class foo
{
private:
    int f;
public:
    void show();
    void show() const;
};

int main(int argc, char *argv[])
{
    foo f1;
    const foo f2 = f1;
    const foo *pf = &f2;

    f1.show();
    f2.show();
    pf->show();

    return 0;
}

void foo::show()
{
    std::cout << "I am normal show!\n";
}

void foo::show() const
{
    std::cout << "I am const show!\n";
}
