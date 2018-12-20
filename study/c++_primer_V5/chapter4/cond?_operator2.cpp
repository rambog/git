/*======================================================================
*        filename: cond?_operator2.cpp
*        author: rambogui
*        data: 2018-12-20 13:51:35
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using std::cout;
    int grade = 50;

    cout << ((grade < 60) ? "fail" : "pass");
    cout << (grade < 60) ? "fail" : "pass";
    cout << grade < 60 ? "fail" : "pass";

    return 0;
}
