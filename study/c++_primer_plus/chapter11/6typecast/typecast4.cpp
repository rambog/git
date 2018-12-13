/*======================================================================
*        filename: typecast4.cpp
*        author: rambogui
*        data: 2018-12-08 16:39:50
======================================================================*/

#include <iostream>

class foo
{
private:
    int tmp;
public:
    foo() {}
    foo(const int &);

    operator int() const;
    friend int operator+ (const foo &, const foo &);
};

int main(int argc, char *argv[])
{
    int i = 0;
    foo f(100);

    i + f;
    i = f;

    return 0;
}

foo::foo(const int &n)
{
    tmp = n;
}

foo::operator int() const
{
    return tmp;
}

int operator+ (const foo &n, const foo &f)
{
    using namespace std;

    cout << "using foo operator+" << endl;

    return n.tmp+f.tmp;
}
