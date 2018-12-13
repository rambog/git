/*======================================================================
*        filename: funcoverld.cpp
*        author: rambogui
*        data: 2018-12-10 08:53:02
======================================================================*/

#include <iostream>

void foo(int, int);

void foo(int &, int &);

int main(int argc, char *argv[])
{
    int f1, f2;

    foo(f1, f2);

    return 0;
}

void foo(int f1, int f2)
{
    using namespace std;
    cout << "I am para" << endl;
}

void foo(int &f1, int &f2)
{
    using namespace std;
    cout << "I am ref" << endl;
}
