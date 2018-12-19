/*======================================================================
*        filename: iterator_binarysearch.cpp
*        author: rambogui
*        data: 2018-12-19 15:51:31
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec;
    int temp;

    while (std::cin >> temp)
        ivec.push_back(temp);

    std::cin >> temp;

    std::vector<int>::iterator beg = ivec.begin();
    std::vector<int>::iterator end = ivec.end();
    std::vector<int>::iterator mid = beg + (end-beg)/2;

    while (mid != end && *mid != temp) {
        if (temp < *mid)
            end = mid;
        else
            beg = mid+1;
        mid = beg + (end-beg)/2;
    }

    return 0;
}
