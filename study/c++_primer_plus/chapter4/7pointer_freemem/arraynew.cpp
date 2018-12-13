/*======================================================================
*        filename: arraynew.cpp
*        author: rambogui
*        data: 2018-11-26 10:33:18
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    double *p3 = new double [3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout << p3[1] << endl;

    p3 += 1;
    cout << p3[0] << endl;
    cout << p3[1] << endl;

    p3 -= 1;
    delete [] p3;

    return 0;
}
