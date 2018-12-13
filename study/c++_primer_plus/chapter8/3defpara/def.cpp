/*======================================================================
*        filename: def.cpp
*        author: rambogui
*        data: 2018-12-01 10:17:39
======================================================================*/

#include <iostream>

int foo(int, int n = 1, int n1 = 4);

int main(int argc, char *argv[])
{
    //foo(5);
    foo(1,3);
    return 0;
}

int foo(int n1, int n2, int n3)
{
    using namespace std;

    cout << n1 << " " << n2 << endl;
}
