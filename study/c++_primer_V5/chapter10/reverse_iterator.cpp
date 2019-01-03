/*======================================================================
*        filename: reverse_iterator.cpp
*        author: rambogui
*        data: 2019-01-03 16:37:35
======================================================================*/

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::deque;

int main(int argc, char *argv[])
{
    vector<int> iv = {1,2,3,4,5,6,7,8,9};
    deque<int> ideq;
   
    copy(iv.rbegin(), iv.rend(), front_inserter(ideq));
    for_each(ideq.begin(), ideq.end(), [](int tmp)->void
                                        { cout << tmp << ' '; });
    cout << endl;

    return 0;
}
