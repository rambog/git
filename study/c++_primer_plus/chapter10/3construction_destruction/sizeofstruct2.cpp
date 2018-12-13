/*======================================================================
*        filename: sizeofstruct2.cpp
*        author: rambogui
*        data: 2018-12-06 09:19:54
======================================================================*/

#include <iostream>

struct foo1 { short s1; char c1; int i1; };
struct foo2 { short s1; char c1; double d1; char c2; int i1; };

struct foo3 { char c1; foo1 f1; };
struct foo4 { char c1; foo2 f2; };
struct foo5 { char c1; foo1 f1; foo2 f2; };

int main(int argc, char *argv[])
{
    using namespace std;

    cout << sizeof(foo1) << endl;
    cout << sizeof(foo2) << endl;
    cout << sizeof(foo3) << endl;
    cout << sizeof(foo4) << endl;
    cout << sizeof(foo5) << endl;

    return 0;
}
