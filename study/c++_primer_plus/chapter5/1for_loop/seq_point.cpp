/*======================================================================
*        filename: seq_point.cpp
*        author: rambogui
*        data: 2018-11-27 10:39:05
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int i;

    cout << (i = 20, 2*i) << endl;
    cout << i << endl;
    cout << (1*i++ + 2*i++) << endl;

    return 0;
}
