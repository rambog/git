/*======================================================================
*        filename: twofile2.cpp
*        author: rambogui
*        data: 2018-12-03 13:31:12
======================================================================*/

#include <iostream>

extern int tom;
static int dick = 10;
int harry = 200;

void remote_access()
{
    using namespace std;

    cout << "remote_access() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
}
