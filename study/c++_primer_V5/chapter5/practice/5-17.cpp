/*======================================================================
*        filename: 5-17.cpp
*        author: rambogui
*        data: 2018-12-20 22:18:25
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec1 = {0, 1, 1, 2};
    std::vector<int> ivec2 = {0, 1, 1, 2, 3, 5, 8};
    bool substr = true;

    for (std::vector<int>::iterator iter1 = ivec1.begin(), iter2 = ivec2.begin();
            iter1 != ivec1.end() && iter2 != ivec2.end(); ++iter1, ++iter2)
        if (*iter1 != *iter2) {
            substr = false;
            break;
        }

    if (substr)
        std::cout << "is sub" << std::endl;
    else
        std::cout << "not sub" << std::endl;

    return 0;
}
