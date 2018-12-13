/*======================================================================
*        filename: structbit.cpp
*        author: rambogui
*        data: 2018-11-27 13:49:34
======================================================================*/

#include <iostream>

struct foo
{
    long long f1:8;
    char f2[8];
};

int main(int argc, char *argv[])
{
    using namespace std;
    foo tmp;

    cout << sizeof(foo) << endl;
    cout << hex;
    cout << &tmp << " " << (unsigned long long)tmp.f2 << endl;

    return 0;
}
