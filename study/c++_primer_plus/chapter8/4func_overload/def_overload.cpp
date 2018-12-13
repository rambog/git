/*======================================================================
*        filename: def_overload.cpp
*        author: rambogui
*        data: 2018-12-01 10:15:31
======================================================================*/

#include <iostream>

void foo(int, int);
void foo(int);
int foo(int);

int main(int argc, char *argv[])
{
    foo(1, 3);
    foo(9);
    return 0;
}

void foo(int n1, int n2)
{
    using namespace std;

    cout << n1 << " " << n2 << endl;
}

void foo(int n1)
{
    using namespace std;

    cout << n1 << endl;
}

int foo(int n1)
{
    using namespace std;
    cout << "const " << n1 << endl;
    return 0;
}
