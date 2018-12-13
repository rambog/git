/*======================================================================
*        filename: cubes.cpp
*        author: rambogui
*        data: 2018-11-30 11:33:39
======================================================================*/

#include <iostream>
double cube(double a);
double refcube(double &a);
int main(int argc, char *argv[])
{
    using namespace std;

    double x = 3.0;
    
    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;

    return 0;
}

double cube(double a)
{
    a *= a*a;
    return a;
}

double refcube(double &ra)
{
    ra *= ra*ra;
    return ra;
}
