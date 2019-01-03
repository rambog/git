/*======================================================================
*        filename: 10-28.cpp
*        author: rambogui
*        data: 2019-01-03 15:57:35
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <deque>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::deque;

int main(int argc, char *argv[])
{
    vector<int> iv = {1,2,3,4,5,6,7,8,9};
    vector<int> ivb1, ivb2, ivb3;
    deque<int> ideq; 

    copy(iv.begin(), iv.end(), back_inserter(ivb1));
    for_each(ivb1.begin(), ivb1.end(), [](int i)->void
                                    { cout << i << ' ';});
    cout << endl;

    copy(iv.begin(), iv.end(), inserter(ivb2, ivb2.begin()));
    for_each(ivb2.begin(), ivb2.end(), [](int i)->void
                                    { cout << i << ' ';});
    cout << endl;

    copy(iv.begin(), iv.end(), front_inserter(ideq));
    sort(ideq.begin(), ideq.end());
    for_each(ideq.begin(), ideq.end(), [](int i)->void
                                        { cout << i << ' ';});
    cout << endl;

    return 0;
}
