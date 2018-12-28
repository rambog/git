/*======================================================================
*        filename: resize.cpp
*        author: rambogui
*        data: 2018-12-27 10:50:33
======================================================================*/

#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cin;
using std::cout;

int main(int argc, char *argv[])
{
    vector<int> iv = {1,2,3,4,5,6,7,8,9,10};

    iv.resize(12);
    for (int tmp : iv)
        cout << tmp << ' ';
    cout << endl;

    iv.resize(15, 100);
    for (int tmp : iv)
        cout << tmp << ' ';
    cout << endl;

    iv.resize(5);
    for (int tmp : iv)
        cout << tmp << ' ';
    cout << endl;

    return 0;
}
