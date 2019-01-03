/*======================================================================
*        filename: 10-34.cpp
*        author: rambogui
*        data: 2019-01-03 17:02:37
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main(int argc, char *argv[])
{
    vector<int> iv = {1,2,3,4,5,6,7,8,9};

    for_each(iv.crbegin(), iv.crend(),
            [](int i) -> void
            { cout << i << ' '; });
    cout << endl;

    return 0;
}
