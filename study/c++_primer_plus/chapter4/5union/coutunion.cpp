/*======================================================================
*        filename: coutunion.cpp
*        author: rambogui
*        data: 2018-11-24 17:09:14
======================================================================*/

#include <iostream>
#include <climits>

union u4all
{
    char char_val;
    int int_val;
    long long_val;
    double double_val;
};

int main(int argc, char *argv[])
{
    using namespace std;
    u4all tmp;
    int itmp;

    tmp.char_val = 'A';
    cout << tmp.char_val << endl;

    tmp.int_val = 65536;
    cout << tmp.int_val << endl;

    itmp = LONG_MAX;
    tmp.long_val = LONG_MAX;
    cout << tmp.long_val << endl;

    tmp.double_val = 19.124214;
    cout << tmp.double_val << endl;

    tmp.long_val = 0x4142434445464748;
    cout << tmp.char_val << endl;
    cout << hex;
    cout << tmp.long_val << endl;

    return 0;
}
