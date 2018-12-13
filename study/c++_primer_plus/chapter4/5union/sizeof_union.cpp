/*======================================================================
*        filename: sizeof_union.cpp
*        author: rambogui
*        data: 2018-11-24 17:06:02
======================================================================*/

#include <iostream>

union one4all
{
    char char_val;
    int int_val;
    long long_val;
    double double_val;
};

int main(int argc, char *argv[])
{
    using namespace std;
    one4all tmp;
    cout << sizeof(one4all) << endl;
    cout << sizeof tmp << endl;
    return 0;
}
