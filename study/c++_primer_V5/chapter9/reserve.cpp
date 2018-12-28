/*======================================================================
*        filename: reserve.cpp
*        author: rambogui
*        data: 2018-12-27 13:34:59
======================================================================*/

#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    vector<int> iv = {1,2,3,4,5,6,7,8,9};

    cout << iv.capacity() << endl;
    iv.reserve(iv.capacity());
    cout << iv.capacity() << endl;
    iv.reserve(iv.capacity()+1);
    cout << iv.capacity() << endl;

    return 0;
}
