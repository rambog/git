/*======================================================================
*        filename: 10-27.cpp
*        author: rambogui
*        data: 2019-01-03 15:44:38
======================================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

using std::endl;
using std::cout;
using std::cin;
using std::vector;

int main(int argc, char *argv[])
{
    vector<int> iv1 = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10}, iv2;

    unique_copy(iv1.begin(), iv1.end(), back_inserter(iv2)); 

    for_each(iv1.begin(), iv1.end(),
            [](int tmp) -> void
            { cout << tmp << ' '; });
    cout << endl;

    for_each(iv2.begin(), iv2.end(), 
            [](int tmp) -> void
            { cout << tmp << ' ';});
    cout << endl;

    return 0;
}
