/*======================================================================
*        filename: file2.cpp
*        author: rambogui
*        data: 2018-12-03 15:58:16
======================================================================*/

#include <iostream>

static int global;

int foo()
{
    using namespace std;

    cout << &global << endl;
    return 0;
}
