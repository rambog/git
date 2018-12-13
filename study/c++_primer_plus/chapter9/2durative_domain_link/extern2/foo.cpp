/*======================================================================
*        filename: foo.cpp
*        author: rambogui
*        data: 2018-12-03 11:28:03
======================================================================*/

#include <iostream>
#include "foo.h"

int foo()
{
    using namespace std;
    for (int i = 0; i < 12; i++) {
        cout << months1[i] << ' ';
    }
    cout << endl;
    return 0;
}
