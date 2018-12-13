/*======================================================================
*        filename: firstenumis0.cpp
*        author: rambogui
*        data: 2018-11-26 08:39:06
======================================================================*/

#include <iostream>

enum foo 
{
    foo1,
    foo2,
    foo3,
    foo4
};

int main(int argc, char *argv[])
{
    using namespace std;
    foo ftmp;

    cout << sizeof ftmp << endl;
    ftmp = foo1;
    cout << ftmp << endl;
    ftmp = foo4;
    cout << ftmp << endl;

    return 0;
}
