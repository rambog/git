/*======================================================================
*        filename: constructor_assigned_equalope.cpp
*        author: rambogui
*        data: 2018-12-25 09:34:47
======================================================================*/

#include <iostream>
#include <string>
#include <cstring>

class foo {
public:
    foo();
    foo(const char *str);
    foo &operator= (const char *str);
private:
    std::string foostr;
};

foo::foo()
{
    std::cout << "foo default constructor\n";
}

foo::foo(const char *str)
{
    std::cout << "foo constructor\n";
    foostr = str;
}

foo &foo::operator= (const char *str)
{
    std::cout << "foo operator=\n";
    foostr = str;
}

class fooo {
public:
    //fooo(const char *str) : f(str) { }
    fooo(const char *str) { f = str; }
private:
    foo f;
};

int main(int argc, char *argv[])
{
    foo f = "rambo";
    std::cout << std::endl;
    foo f2;
    f2 = "rambo";

    std::cout << "\n\n";
    fooo("rambo");

    return 0;
}
