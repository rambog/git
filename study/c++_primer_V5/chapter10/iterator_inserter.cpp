/*======================================================================
*        filename: iterator_inserter.cpp
*        author: rambogui
*        data: 2019-01-03 15:31:06
======================================================================*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using std::endl;
using std::cout;
using std::cin;
using std::vector;

int main(int argc, char *argv[])
{
    vector<int> iv = {1,2,3,4,5,6,7,8,9,10};

    auto it = inserter(iv, iv.begin()+5);

    cout << *(iv.begin()+5) << ' ' << endl;
    for_each(iv.begin(), iv.end(), 
                [](int i) -> void
                { cout << i << ' '; });
    cout << endl;
    
    *it = 100; 

    for_each(iv.begin(), iv.end(), 
                [](int i) -> void
                { cout << i << ' '; });
    cout << endl;

    ++it;
    *it = 1000;

    for_each(iv.begin(), iv.end(), 
                [](int i) -> void
                { cout << i << ' '; });
    cout << endl;

    return 0;
}
