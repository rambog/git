/*======================================================================
*        filename: twotemplate.cpp
*        author: rambogui
*        data: 2018-12-03 09:06:57
======================================================================*/

#include <iostream>

template <class T1, class T2>
void foo(T1 t1, T2 t2);

template <class T>
void foo(T t1, T t2);

int main(int argc, char *argv[])
{
    int tmp1 = 1;
    int tmp2 = 1;
    foo(tmp1, tmp2);
    return 0;
}

template <class T1, class T2>
void foo(T1 t1, T2 t2)
{
    using namespace std;
    cout << "I am T1 T2" << endl;
}

template <class T>
void foo(T t1, T t2)
{
    using namespace std;
    cout << "I am T" << endl;
}
