/*======================================================================
*        filename: choices.cpp
*        author: rambogui
*        data: 2018-12-01 15:57:16
======================================================================*/

#include <iostream>

template <class T>
T lesser(T a, T b)
{
    using namespace std;
    cout << "I am template" << endl;
    return a < b ? a : b;
}

int lesser(int a, int b)
{
    using namespace std;
    cout << "I am not template" << endl;
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

int foo(int a)
{
    return 0;
}

int main(int argc, char *argv[])
{
    using namespace std;
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;
    cout << lesser(x, y) << endl;
    cout << lesser<>(m, n) << endl;
    cout << lesser<int>(x, y) << endl;

    foo(1.0);
    return 0;
}
