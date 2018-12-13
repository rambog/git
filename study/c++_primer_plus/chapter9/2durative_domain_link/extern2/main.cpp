/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-03 11:33:18
======================================================================*/

#include <iostream>
#include "foo.h"

int foo();

int main(int argc, char *argv[])
{
    using namespace std;

    for (int i = 0; i < 12; i++) {
        cout << months1[i] << ' ' ;
    }
    cout << endl;

    foo();


    return 0;
}
