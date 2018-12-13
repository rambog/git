/*======================================================================
*        filename: refapointer.cpp
*        author: rambogui
*        data: 2018-11-30 10:28:12
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    int tmp = 10;
    int *pt;
    pt = &tmp;
    int *&pref = pt;
    //int *&pref;
    cout << *pref << endl;
    return 0;
}
