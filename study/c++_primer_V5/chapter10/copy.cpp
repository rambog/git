/*======================================================================
*        filename: copy.cpp
*        author: rambogui
*        data: 2018-12-29 10:33:47
======================================================================*/

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::vector<int> iv1 = {1,2,3,4,5,6,7,8,9};
    std::vector<int> iv2;

    copy(iv1.begin(), iv1.end(), back_inserter(iv2));

    for (auto tmp : iv2)
        std::cout << tmp << ' ';
    std::cout << std::endl;

    return 0;
}
