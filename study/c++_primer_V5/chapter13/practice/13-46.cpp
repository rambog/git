/*======================================================================
*        filename: 13-46.cpp
*        author: rambogui
*        data: 2019-01-08 15:54:44
======================================================================*/

#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cout;
using std::cin;

int f()
{
    return 1;
}

int main(int argc, char *argv[])
{
    vector<int> vi(100);

    int &&r1 = f();
    int &r2 = vi[0];
    int &r3 = r1;
    int &&r4 = vi[0]*f();

    return 0;
}
