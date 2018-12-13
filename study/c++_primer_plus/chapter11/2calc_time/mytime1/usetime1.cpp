/*======================================================================
*        filename: usetime1.cpp
*        author: rambogui
*        data: 2018-12-07 11:11:42
======================================================================*/

#include <iostream>
#include "mytime1.h"

int main(int argc, char *argv[])
{
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    morefixing.Show();
    cout << endl;

    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;

    return 0;
}
