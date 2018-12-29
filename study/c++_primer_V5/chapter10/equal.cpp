/*======================================================================
*        filename: equal.cpp
*        author: rambogui
*        data: 2018-12-29 08:51:47
======================================================================*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using std::list;
using std::vector;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    vector<int> iv = {1,2,3,4,5,6,7,8,9,10,11};
    list<int> il = {1,2,3,4,5,6,7,8,9,10};

    if (equal(iv.begin(), iv.end(), il.begin()))
        cout << "equal\n";
    else
        cout << "not equal\n";

    return 0;
}
