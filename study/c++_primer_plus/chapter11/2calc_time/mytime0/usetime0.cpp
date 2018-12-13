/*======================================================================
*        filename: usetime0.cpp
*        author: rambogui
*        data: 2018-12-07 11:00:11
======================================================================*/

#include <iostream>
#include "mytime0.h"

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

    cout << "coding time = ";
    coding.Show();

    cout << "fixing time = ";
    fixing.Show();

    total = coding.Sum(fixing);
    cout << "coding.Sum(fixing) = ";
    total.Show();

    return 0;
}
