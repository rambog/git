/*======================================================================
*        filename: decltype.cpp
*        author: rambogui
*        data: 2018-12-01 16:16:13
======================================================================*/

#include <iostream>

template <class T1, class T2>
auto tmp(T1 t1, T2 t2) -> decltype(t1+t2)
{
    decltype(t1+t2) result;
    result = t1+t2;
    return result;
}

int main(int argc, char *argv[])
{
    using namespace std;

    int foo1 = 10;
    double foo2 = 10.1;
    cout << sizeof tmp(foo1, foo2) << endl;
    cout << tmp(foo1, foo2) << endl;

    decltype ((foo1)) fooref = foo1;

    cout << fooref++ << ' ';
    cout << foo1 << endl;

    return 0;
}
