/*======================================================================
*        filename: file1.cpp
*        author: rambogui
*        data: 2018-12-03 15:58:10
======================================================================*/

#include <iostream>

extern int global = 20;

int foo();

int main(int argc, char *argv[])
{
    using namespace std;

    cout << &global << endl;

    foo();

    return 0;
}
