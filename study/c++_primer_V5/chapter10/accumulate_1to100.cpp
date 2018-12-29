/*======================================================================
*        filename: accumulate_1to100.cpp
*        author: rambogui
*        data: 2018-12-29 08:38:46
======================================================================*/

#include <iostream>
#include <vector>
#include <numeric>

using std::vector;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    vector<int> iv;
    for (int i = 1; i <= 100; i++)
        iv.push_back(i);

    std::cout << "sum of 1 to 100: "
              << accumulate(iv.begin(), iv.end(), 0) << std::endl;

    return 0;
}
