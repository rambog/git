/*======================================================================
*        filename: nsignenum.cpp
*        author: rambogui
*        data: 2018-11-26 08:55:38
======================================================================*/

#include <iostream>

enum foo
{
    f1 = -5,
    f2,
    f3,
    f4,
    f5,
    f6,
    f7
};


int main(int argc, char *argv[])
{
    using namespace std;

    cout << f1 << ' ';
    cout << f2 << ' ';
    cout << f3 << ' ';
    cout << f4 << ' ';
    cout << f5 << ' ';
    cout << f6 << ' ';
    cout << f7 << endl;

    return 0;
}
