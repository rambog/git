/*======================================================================
*        filename: replace_copy.cpp
*        author: rambogui
*        data: 2018-12-29 10:45:58
======================================================================*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main(int argc, char *argv[])
{
    std::vector<int> iv = {1,1,2,2,3,3,4,4};
    std::vector<int> iv2 = {4,4,5,5,6,6};

    //replace_copy(iv.begin(), iv.end(), iv2.begin(), 2, 100);
    replace_copy(iv.begin(), iv.end(), back_inserter(iv2), 2, 100);

    for (auto tmp : iv2)
        std::cout << tmp << ' ';
    std::cout << std::endl;

    return 0;
}
