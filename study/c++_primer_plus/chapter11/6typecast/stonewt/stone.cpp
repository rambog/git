/*======================================================================
*        filename: stone.cpp
*        author: rambogui
*        data: 2018-12-08 14:46:18
======================================================================*/

#include <iostream>
#include "stonewt.h"

using std::cout;

void display(const Stonewt &st, int n);

int main(int argc, char *argv[])
{
    Stonewt incognito = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    cout << "The celebrity weighed ";
    incognito.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The President weighed ";
    taft.show_lbs();

    incognito = 276.8;
    taft = 325;

    return 0;
}
