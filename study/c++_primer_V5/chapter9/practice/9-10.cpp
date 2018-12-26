/*======================================================================
*        filename: 9-10.cpp
*        author: rambogui
*        data: 2018-12-26 08:32:23
======================================================================*/

#include <iostream>
#include <vector>
using std::vector;

int main(int argc, char *argv[])
{
    vector<int> v1;
    const vector<int> v2;

    vector<int>::iterator iter1 = v1.begin();
    vector<int>::const_iterator iter2 = v1.begin();

    vector<int>::const_iterator iter3 = v2.begin();

    vector<int>::const_iterator iter4 = v1.cbegin();

    vector<int>::const_iterator iter5 = v2.cbegin();

    v1.cbegin();
    v2.begin();

    return 0;
}
