/*======================================================================
*        filename: def_overload2.cpp
*        author: rambogui
*        data: 2018-12-01 10:29:01
======================================================================*/

#include <iostream>

void foo(int);
void foo(long);

int main(int argc, char *argv[])
{
    foo(1LL);
    return 0;
}

void foo(int)
{
    using namespace std;
    cout << "I am int" << endl;
}

void foo(long)
{
    using namespace std;
    cout << "I am long" << endl;
}
