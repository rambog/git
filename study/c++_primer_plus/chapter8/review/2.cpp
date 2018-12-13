/*======================================================================
*        filename: 2.cpp
*        author: rambogui
*        data: 2018-12-01 17:04:28
======================================================================*/

#include <iostream>

void song(char *name, int times = 1);

int main(int argc, char *argv[])
{
    song("I am rambo");
    return 0;
}

void song(char *name, int times)
{
    using namespace std;
    cout << name << endl;
    cout << times << endl;
}
