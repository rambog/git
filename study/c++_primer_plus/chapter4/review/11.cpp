/*======================================================================
*        filename: 11.cpp
*        author: rambogui
*        data: 2018-11-27 08:47:35
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    double ted = 10.9;
    double *pted = &ted;

    cout << *pted << " " << pted << endl;

    return 0;
}
