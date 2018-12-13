/*======================================================================
*        filename: use_new.cpp
*        author: rambogui
*        data: 2018-11-26 10:01:45
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int nights = 1001;
    int *pt = new int;
    *pt = 1001;

    cout << "nights value = " << nights << ": location " << &nights << endl;

    cout << "int " << "value = " << *pt << ": location = " << pt <<endl;

    double *pd = new double;
    *pd = 10000001.0;

    cout << "double value = " << *pd << ": location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;

    cout << "sizeof pt = " << sizeof(pt);
    cout << ": sizeof *pt = " << sizeof(*pt) << endl;
    cout << "sizeof pd = " << sizeof pd;
    cout << ": sizeof *pd = " << sizeof(*pd) << endl;

    return 0;
}
