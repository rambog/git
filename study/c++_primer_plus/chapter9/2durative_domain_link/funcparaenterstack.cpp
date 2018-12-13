/*======================================================================
*        filename: funcparaenterstack.cpp
*        author: rambogui
*        data: 2018-12-03 10:16:16
======================================================================*/

#include <iostream>

static int glob = 0;

int foo1();
int foo2();
void foo3(int, int);

int main(int argc, char *argv[])
{
    foo3(foo2(), foo1());
    return 0;
}

int foo1()
{
    if (glob > 0) glob = 10;
    else glob = -10;
}

int foo2()
{
    glob++;
}

void foo3(int n1, int n2)
{
    using namespace std;
    cout << "I am foo3 " << glob << endl;
}
