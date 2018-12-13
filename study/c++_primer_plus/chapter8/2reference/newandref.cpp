/*======================================================================
*        filename: newandref.cpp
*        author: rambogui
*        data: 2018-11-30 14:28:59
======================================================================*/

#include <iostream>

int &foo();

int main(int argc, char *argv[])
{
    using namespace std;
    int *tmp = &foo();
    cout << *tmp << endl;
    delete tmp;
    return 0;
}

int &foo()
{
    int *tmp = new int;
    *tmp = 5;
    return *tmp;
}
