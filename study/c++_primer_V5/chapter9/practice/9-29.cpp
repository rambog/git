/*======================================================================
*        filename: 9-29.cpp
*        author: rambogui
*        data: 2018-12-27 10:53:29
======================================================================*/

#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cin;
using std::cout;

int main(int argc, char *argv[])
{
    vector<int> iv(25, 100);

    for (auto i : iv)
        cout << i << ' ';
    cout << endl;

    iv.resize(100);
    for (auto i : iv)
        cout << i << ' ';
    cout << endl;

    iv.resize(10);
    for (auto i : iv)
        cout << i << ' ';
    cout << endl;

    return 0;
}
