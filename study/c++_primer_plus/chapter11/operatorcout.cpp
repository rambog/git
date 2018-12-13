/*======================================================================
*        filename: operatorcout.cpp
*        author: rambogui
*        data: 2018-12-08 09:22:38
======================================================================*/

#include <iostream>
#include <ostream>

class foo
{
    int f1;
    int f2;
    std::string str;
public:
    foo() {}
    foo(const int &, const int &, const std::string &);
    void show() const;
};

std::ostream & operator<< (std::ostream &os, const foo &f);

int main(int argc, char *argv[])
{
    foo f(10, 11, "rambo");
    f.show();
    foo f2(20, 21, "guiyao");

    std::cout << f << f2;
    return 0;
}

foo::foo(const int &n1, const int &n2, const std::string &s)
{
    f1 = n1;
    f2 = n2;
    str = s;
}

void foo::show() const
{
    using namespace std;

    cout << f1 << ' ' << f2 << ' ' << str << endl;
}

std::ostream & operator<< (std::ostream &os, const foo &f)
{
    f.show();
    return os;
}
