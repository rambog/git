/*======================================================================
*        filename: 10-37.cpp
*        author: rambogui
*        data: 2019-01-03 17:13:37
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

using std::vector;
using std::endl;
using std::cout;
using std::cin;
using std::list;

int main(int argc, char *argv[])
{
    vector<int> iv = {0,1,2,3,4,5,6,7,8,9}; 
    list<int> ilst;

    copy(iv.begin()+3, iv.begin()+8, front_inserter(ilst));

    for_each(ilst.begin(), ilst.end(),
            [](int i)->void { cout << i << ' ';});
    cout << endl;
        
    return 0;
}
