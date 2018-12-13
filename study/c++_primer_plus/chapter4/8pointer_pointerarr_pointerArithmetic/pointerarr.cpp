/*======================================================================
*        filename: pointerarr.cpp
*        author: rambogui
*        data: 2018-11-26 11:37:38
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    int tell[8];
    int (*pas)[4] = (int (*)[4])&tell;
    //int (*pas)[8] = &tell;
    int (*tmp)[];
    tmp = (int (*)[])tell;

    for (int i = 0; i < sizeof tell/sizeof(int); i++) 
        tell[i] = i;

    cout << pas << " " << pas+1 << endl;
    cout << &pas << endl;
    cout << tell << " " << &tell[4] << " " << &tell[7] << endl;
    cout << pas+1 << endl; 
    cout << tmp << endl;

    return 0;
}
