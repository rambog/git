/*======================================================================
*        filename: 9-33.cpp
*        author: rambogui
*        data: 2018-12-27 11:26:49
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

    auto begin = iv.begin();

    while (begin != iv.end()) {
        ++begin;
        /*begin =*/ iv.insert(begin, 0);
        ++begin;
        ++begin;
    }

    for (auto i : iv)
        cout << i << ' ';
    cout << endl;

    return 0;
}
