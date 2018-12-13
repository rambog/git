/*======================================================================
*        filename: inline.cpp
*        author: rambogui
*        data: 2018-11-30 09:54:30
======================================================================*/

#include <iostream>

inline double square(double x) { return x*x; }

int main(int argc, char *argv[])
{
    using namespace std;

    double a,b;
    double c = 13.0;

    a = square(5.0);
    b = square(4.5+7.5);

    cout << "a = " << a << ", b = " << b << "\n";
    cout << "c = " << c;
    cout << ", c squared = " << square(c++) << "\n";
    cout << "Now c = " << c << "\n";

    return 0;
}