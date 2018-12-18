/*======================================================================
*        filename: literal_int.cpp
*        author: rambogui
*        data: 2018-12-18 09:40:24
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    //cout << 0xffffffffffffffff << endl;
    cout << 0xffffffffffffffff + 1 << endl;
    cout << 0xffffffff + 1 << endl;
    cout << 0xffff + 1 << endl;
    cout << 0xff + 1 << endl;

    cout << sizeof(0xffffffffffffffff + 1) << endl;
    cout << sizeof(0xffffffff + 1) << endl;
    cout << sizeof(0xffff + 1) << endl;
    cout << sizeof(0xff + 1) << endl;
    return 0;
}
