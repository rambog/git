/*======================================================================
*        filename: float_type.cpp
*        author: rambogui
*        data: 2018-11-23 14:29:22
======================================================================*/

#include <iostream>
#include <cfloat>

int main(int argc, char *argv[])
{
    using namespace std;

    cout << sizeof(float) << ' ' << sizeof(double) << ' ' << sizeof(long double) << endl;

    cout << FLT_MAX << ' ' << FLT_MIN << endl;
    cout << DBL_MAX << ' ' << DBL_MIN << endl;
    cout << LDBL_MAX << ' ' << LDBL_MIN << endl;

    return 0;
}
