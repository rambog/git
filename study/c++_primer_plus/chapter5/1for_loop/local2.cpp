/*======================================================================
*        filename: local2.cpp
*        author: rambogui
*        data: 2018-11-27 10:30:53
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int x = 20;
    {
        int x = 100;
        cout << x << endl;
    }
    cout << x << endl;

    return 0;
}
