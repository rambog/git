/*======================================================================
*        filename: ref.cpp
*        author: rambogui
*        data: 2018-12-08 09:51:51
======================================================================*/

#include <iostream>

int foo(int &);

int main(int argc, char *argv[])
{
    using namespace std;

    int tmp = 10;
    
    const int &ref = foo(tmp);

    cout << foo(tmp) << endl;
    cout << ref << endl;

    cout << &tmp << ' ' << &ref << endl;

    return 0;
}

int foo(int &n)
{
    return n;
}
