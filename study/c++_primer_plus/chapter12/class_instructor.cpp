/*======================================================================
*        filename: class_instructor.cpp
*        author: rambogui
*        data: 2018-12-10 08:23:14
======================================================================*/

#include <iostream>

class foo
{
private:
    int fdata;
public:
    foo();
    foo(const foo &);
};

class fooo
{
};

foo foofunc(foo);

int main(int argc, char *argv[])
{
    foo f;
    foo f2 = f;
    foo f3 = foo(f3);
    f3 = f2;

    fooo fo;
    fooo fo1 = fooo(fo);

    std::cout << "call foofunc:!\n";
    foofunc(f);

    return 0;
}

foo::foo()
{
    std::cout << "I am def instructor!\n";
}

foo::foo(const foo &f)
{
    std::cout << "I am cpy instructor!\n";
}

foo foofunc(foo f)
{
    return f;
}
