/*======================================================================
*        filename: arr_address.cpp
*        author: rambogui
*        data: 2018-11-26 11:33:17
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    short tell[10];
    cout << tell << endl;
    cout << &tell << endl;

    cout << tell + 1 << endl;
    cout << &tell + 1 << endl;

    return 0;
}
