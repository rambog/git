/*======================================================================
*        filename: init_ptr.cpp
*        author: rambogui
*        data: 2018-11-26 09:47:37
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int higgens = 5;
    int *pt = &higgens;

    cout << "Value of higgens = " << higgens
         << "; Address of higgens = " << &higgens << endl;
    cout << "Value of *pt = " << *pt
         << "; Value of pt = " << pt << endl;

    return 0;
}
