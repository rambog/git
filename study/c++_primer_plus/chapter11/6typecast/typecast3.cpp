/*======================================================================
*        filename: typecast3.cpp
*        author: rambogui
*        data: 2018-12-08 15:29:24
======================================================================*/

#include <iostream>

using namespace std;

class foo1;
class foo2;

class foo1
{
private:
    int f1;
public:
    foo1() {}
    foo1(const int &n) { f1 = n; }
    foo1(const foo2 &);

    int getval() const { return f1; }
    operator foo2();
    friend foo1 operator+ (const foo1 &, const foo1 &);
};

class foo2
{
private:
    int f2;
public:
    foo2() {}
    foo2(const int &n) { f2 = n; }
    foo2(const foo1 &);

    int getval() const { return f2; }
    operator foo1();
    friend foo2 operator+ (const foo2 &, const foo2 &);
};

int main(int argc, char *argv[])
{
    foo1 f1(1);
    foo2 f2(2);

    f1+f2;

    return 0;
}

foo1::foo1(const foo2& f2)
{
    f1 = f2.getval();
}

foo1::operator foo2()
{
    return foo2(f1);
}

foo1 operator+ (const foo1 &f1_1, const foo1 &f1_2)
{
    return foo1(f1_1.f1+f1_2.f1);
}

foo2::foo2(const foo1& f1)
{
    f2 = f1.getval();
}

foo2::operator foo1()
{
    return foo1(f2);
}

foo2 operator+ (const foo2 &f2_1, const foo2 &f2_2)
{
    return foo2(f2_1.f2+f2_2.f2);
}
