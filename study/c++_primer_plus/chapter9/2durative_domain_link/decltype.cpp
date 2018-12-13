/*======================================================================
*        filename: decltype.cpp
*        author: rambogui
*        data: 2018-12-03 09:03:36
======================================================================*/

#include <iostream>

template <class T1, class T2>
auto foofunc(T1 t1, T2 t2) -> decltype(t1+t2);

int main(int argc, char *argv[])
{
    using namespace std;
    cout << sizeof foofunc(1, 1.0) << endl;
    cout << foofunc(1, 1.2342) << endl;
    return 0;
}

template <class T1, class T2>
auto foofunc(T1 n1, T2 n2) -> decltype(n1+n2)
{
    return n1+n2;
}
