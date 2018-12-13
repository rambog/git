/*======================================================================
*        filename: choices.cpp
*        author: rambogui
*        data: 2018-11-26 16:08:01
======================================================================*/

#include <iostream>
#include <vector>
#include <array>

int main(int argc, char *argv[])
{
    using namespace std;

    double a1[4] = {1.2, 2.4, 3.6, 4.8};
    vector<double> a2(4);
    a2[0] = 1.0/3.0;
    a2[1] = 1.0/5.0;
    a2[2] = 1.0/7.0;
    a2[3] = 1.0/9.0;

    //array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    array<double, 4> a3;
    array<double, 4> a4;
    a4 = a3;

    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

    
    //a1[-20000] = 20.2;
    a2.at(10) = 2.3;
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

    return 0;
}
