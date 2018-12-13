/*======================================================================
*        filename: func.cpp
*        author: rambogui
*        data: 2018-11-29 08:59:08
======================================================================*/

#include <iostream>

int cube(int para)
{
    return 1;
}

int cube(double para)
{
    return 2;
}

int cube2(int x, int y);

int main(int argc, char *argv[])
{
    using namespace std;
    cout << cube(1.0) << endl;;
    cout << cube2(5,6) << endl;
    return 0;
}

int cube2(int x1, int x2)
{
    return x1+x2;
}
