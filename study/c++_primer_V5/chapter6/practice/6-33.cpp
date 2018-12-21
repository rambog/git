/*======================================================================
*        filename: 6-33.cpp
*        author: rambogui
*        data: 2018-12-21 15:56:15
======================================================================*/

#include <iostream>
#include <vector>

using std::vector;
typedef vector<int>::const_iterator iviter;

void printvec(iviter beg, iviter end)
{
    if (beg == end) return;

    std::cout << *beg++ << std::endl;
    printvec(beg, end);
}

int main(int argc, char *argv[])
{
    vector<int> ivec = {1,2,3,4,5,6,7,8,9,10};
    printvec(ivec.begin(), ivec.end());
    return 0;
}
