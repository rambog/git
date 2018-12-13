/*======================================================================
*        filename: file1.cpp
*        author: rambogui
*        data: 2018-12-03 08:28:47
======================================================================*/

#include <iostream>
#include "coordin.h"

using namespace std;

int main(int argc, char *argv[])
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y vaules: ";
    while (cin >> rplace.x >> rplace.y) {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit) : ";
    }
    cout << "Bye!\n";

    return 0;
}
