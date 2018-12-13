/*======================================================================
*        filename: pointtoconst.cpp
*        author: rambogui
*        data: 2018-11-29 14:42:52
======================================================================*/

#include <iostream>

const int tmp = 5;

int main(int argc, char *argv[])
{
    using namespace std;
    
    cout << tmp << endl;

    const int *pt = &tmp;
    *((int*)pt) = 6;

    cout << tmp << endl;

    return 0;
}
