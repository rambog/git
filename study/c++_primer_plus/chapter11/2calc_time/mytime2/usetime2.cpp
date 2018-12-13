/*======================================================================
*        filename: usetime2.cpp
*        author: rambogui
*        data: 2018-12-07 15:59:26
======================================================================*/

#include <iostream>
#include "mytime2.h"

int main(int argc, char *argv[])
{
    using namespace std;
    
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = ";
    weeding.Show();
    cout << endl;

    cout << "total work time = ";
    total = weeding+waxing;
    total.Show();
    cout << endl;

    diff = weeding - waxing;
    cout << "weeding time - waxing time = ";
    diff.Show();
    cout << endl;

    adjusted = total * 1.5;
    cout << "adjusted work time = ";
    adjusted.Show();
    cout << endl;

    return 0;
}
