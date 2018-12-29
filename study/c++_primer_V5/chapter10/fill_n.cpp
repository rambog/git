/*======================================================================
*        filename: fill_n.cpp
*        author: rambogui
*        data: 2018-12-29 09:37:35
======================================================================*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> iv;
    fill_n(iv.begin(), iv.size(), 0);
    return 0;
}
