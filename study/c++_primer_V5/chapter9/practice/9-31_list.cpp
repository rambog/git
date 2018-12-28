/*======================================================================
*        filename: 9-31_list.cpp
*        author: rambogui
*        data: 2018-12-27 11:07:43
======================================================================*/

#include <iostream>
#include <list>

using std::list;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    list<int> ilst = {0,1,2,3,4,5,6,7,8,9};
    list<int>::iterator end = ilst.end();
    list<int>::iterator beg = ilst.begin();

    while (beg != end) {
        if (*beg % 2) {
            beg = ilst.insert(beg, *beg);
            beg++;beg++;
        } else
            beg = ilst.erase(beg);
    }

    for (auto i : ilst)
        cout << i << ' ';
    cout << endl;

    return 0;
}
