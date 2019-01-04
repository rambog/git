/*======================================================================
*        filename: set_insert.cpp
*        author: rambogui
*        data: 2019-01-04 16:25:54
======================================================================*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using std::map;
using std::set;
using std::vector;
using std::string;

using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    vector<int> ivec = {2,4,6,8,2,4,6,8};
    set<int> iset;
    iset.insert(ivec.begin(), ivec.end());

    for_each(iset.begin(), iset.end(),
        [](int i) { cout << i << ' '; });
    cout << endl;

    iset.insert({1,3,5,7,1,3,5,7});

    for_each(iset.begin(), iset.end(),
        [](int i) { cout << i << ' '; });
    cout << endl;

    return 0;
}
