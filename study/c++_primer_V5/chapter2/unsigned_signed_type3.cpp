/*======================================================================
*        filename: unsigned_signed_type3.cpp
*        author: rambogui
*        data: 2018-12-18 09:34:15
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    signed char sch = -1;
    unsigned char uch = 10;
    long long ll = 10;

    cout << sizeof sch << ' ' << sizeof uch << endl;
    cout << "sizeof(char add): " << sizeof(sch+uch) << endl; 
    cout << "sizeof(char add llong): " << sizeof(ll+uch) << endl;

    return 0;
}
