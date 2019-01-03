/*======================================================================
*        filename: 10-37_r.cpp
*        author: rambogui
*        data: 2019-01-03 17:22:12
======================================================================*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::list;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    vector<int> iv = {0,1,2,3,4,5,6,7,8,9};
    list<int> ilst(10);

    copy(iv.crbegin()+2, iv.crbegin()+7, ilst.begin());
    for_each(ilst.begin(), ilst.end(),
        [](int i)->void { cout << i << ' ';});
    cout << endl;

    return 0;
}
