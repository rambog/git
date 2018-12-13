/*======================================================================
*        filename: funcpara_ref.cpp
*        author: rambogui
*        data: 2018-11-30 11:39:44
======================================================================*/

#include <iostream>

int foo(const int &a);

int main(int argc, char *argv[])
{
    int tmp = 5;
    foo(tmp);
    foo(tmp+1.0);
    return 0;
}

int foo(const int &a)
{
    using namespace std;
    cout << a << endl;
    return a;
}
