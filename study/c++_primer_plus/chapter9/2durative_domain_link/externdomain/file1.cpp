/*======================================================================
*        filename: file1.cpp
*        author: rambogui
*        data: 2018-12-03 10:44:08
======================================================================*/

#include <iostream>
#include "file1.h"
extern int externg;
int foo()
{
    using namespace std;

    cout << "file1 " << externg << endl;

    return 0;
}
