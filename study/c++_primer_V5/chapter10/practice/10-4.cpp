/*======================================================================
*        filename: 10-3.cpp
*        author: rambogui
*        data: 2018-12-29 09:12:22
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(int argc, char *argv[])
{
    std::vector<double> iv;

    for (int i = 1; i <= 100; i++)
        iv.push_back(i);

    std::cout << accumulate(iv.cbegin(), iv.cend(), 0) << std::endl;

    return 0;
}
