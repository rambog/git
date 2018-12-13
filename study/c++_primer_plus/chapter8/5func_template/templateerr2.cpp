/*======================================================================
*        filename: templateerr2.cpp
*        author: rambogui
*        data: 2018-12-01 14:56:40
======================================================================*/

#include <iostream>

template <class T>
void foo(T, T);

template <> void foo(int ,int);

int main(int argc, char *argv[])
{
    return 0;
}

template <class T>
void foo(T t1, T t2)
{
    using namespace std;
    cout << "I am foo\n";
}

template <> void foo(int n1, int n2)
{
    using namespace std;
    cout << "I am int double\n";
}

