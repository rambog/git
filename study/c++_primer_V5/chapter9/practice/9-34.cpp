/*======================================================================
*        filename: 9-34.cpp
*        author: rambogui
*        data: 2018-12-27 11:32:04
======================================================================*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[])
{
    vector<int> iv = {1,2,3,4,5,6,7,8,9};

    auto iter = iv.begin();
    while (iter != iv.end()) {
        if (*iter % 2)
            iter = iv.insert(iter, *iter);
        ++iter;
        ++iter;
    }

    for (auto i : iv)
        cout << i << ' ';
    cout << endl;

    return 0;
}
