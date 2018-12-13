/*======================================================================
*        filename: mutable.cpp
*        author: rambogui
*        data: 2018-12-03 14:36:51
======================================================================*/

#include <iostream>

struct foo1
{
    int f1;
    int f2;
};

struct foo2
{
    int f1;
    mutable int f2;
};

int main(int argc, char *argv[])
{
    using namespace std;
    foo1 foo1e;
    const foo2 foo2e = {1, 2};

    cout << foo2e.f1 << ' ' << foo2e.f2 << endl;
    foo2e.f2 = 20;
    cout << foo2e.f1 << ' ' << foo2e.f2 << endl;

    return 0;
}
