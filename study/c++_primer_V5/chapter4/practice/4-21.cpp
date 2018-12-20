/*======================================================================
*        filename: 4-21.cpp
*        author: rambogui
*        data: 2018-12-20 14:01:37
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int>::iterator iter = ivec.begin();

    while(iter != ivec.end()) {
        *iter = (*iter%2 ? *iter*2 : *iter);
        ++iter;
    }

    iter = ivec.begin();
    while (iter != ivec.end())
        std::cout << *iter++ << ' ';
    std::cout << std::endl;

    return 0;
}
