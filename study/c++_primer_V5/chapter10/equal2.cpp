/*======================================================================
*        filename: equal2.cpp
*        author: rambogui
*        data: 2018-12-29 08:56:45
======================================================================*/

#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;

class foo2;
class foo1{
private:
    int f1;
public:
    foo1(int i) : f1(i) { }

friend bool operator== (const foo2 &f2, const foo1 &f1);
};

class foo2{
private:
    int f2;
public:
    foo2(int i) : f2(i) { }
friend bool operator== (const foo2 &f2, const foo1 &f1);
};

bool operator== (const foo2 &f2, const foo1 &f1)
{
    return f2.f2 == f1.f1;
}

int operator== (const foo1 &f1, const foo2 &f2)
{
    //return f2==f1;
    return operator==(f2, f1);
}

int main(int argc, char *argv[])
{
    vector<foo1> f1v = {1, 2, 3, 4, 5, 6, 7};
    vector<foo2> f2l = {1, 2, 3, 4};

    if (equal(f1v.begin(), f1v.end(), f2l.begin()))
        std::cout << "equal\n";
    else
        std::cout << "not equal\n";

    return 0;
}
