/*======================================================================
*        filename: int2enum.cpp
*        author: rambogui
*        data: 2018-11-26 08:41:27
======================================================================*/

#include <iostream>

enum foo
{
    foo1, foo2, foo3, foo4, foo5
};

int main(int argc, char *argv[])
{
    using namespace std;
    foo tf;

    tf = (foo)10;
    cout << tf << endl;
    tf = foo1;
    cout << tf << endl;

    return 0;
}
