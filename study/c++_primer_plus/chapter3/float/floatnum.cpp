/*======================================================================
*        filename: floatnum.cpp
*        author: rambogui
*        data: 2018-11-23 15:22:09
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tub = 10.0/3.0;
    double mint = 10.0/3.0;
    const float million = 1.0e6;
    const double millions = 1.0e12;

    cout << "tub :" << tub << " " << tub*million << endl;
    cout << "mint :" << mint << " " << mint*millions << endl;

    return 0;
}
