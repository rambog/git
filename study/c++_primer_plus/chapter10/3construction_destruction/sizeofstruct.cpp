/*======================================================================
*        filename: sizeofstruct.cpp
*        author: rambogui
*        data: 2018-12-06 08:43:57
======================================================================*/

#include <iostream>

struct foo
{
    double d1;
    char c1;
};

struct foo1
{
    int i1;
    char c1;
};

struct foo2
{
    short s1;
    char c1;
};

struct foo3
{
    char c1;
    char c2;
};

struct foo4
{
    double d1;
    char c1;
    int i1;
    int i2;
};

struct foo5
{
    int i1;
    char c1;
    double d1;
    char c2;
    double d2;
};

struct foo6
{
    foo2 f2;
    char c1;
    foo5 f5;
    int i1;
};

struct foo7
{
    double d1;
    char c1;
    //foo5 f5;
    foo1 f1;
};

int main(int argc, char *argv[])
{
    using namespace std;

    cout << sizeof(foo) << endl;
    cout << sizeof(foo1) << endl;
    cout << sizeof(foo2) << endl;
    cout << sizeof(foo3) << endl;
    cout << sizeof(foo4) << endl;

    foo4 f4;
    cout << "the address: ";
    cout << (void*)&(f4.d1) << ' ' << (void*)&(f4.c1) << ' ' << (void*)&(f4.i1) << ' ' << (void*)&(f4.i2) << endl;

    cout << endl;
    cout << sizeof(foo5) << endl;
    foo5 f5;
    cout << (void*)&(f5.i1) << ' ' << (void*)&(f5.c1) << ' ' << (void*)&(f5.d1) << ' ' << (void*)&(f5.c2) 
         << ' ' << (void*)&(f5.d2) << endl;

    cout << endl;
    foo6 f6;
    cout << sizeof f6 << endl;

    cout << endl;
    foo7 f7;
    cout << sizeof f7 << endl;

    return 0;
}
