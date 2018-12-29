/*======================================================================
*        filename: 10-7_1.cpp
*        author: rambogui
*        data: 2018-12-29 10:58:05
======================================================================*/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::vector<int> vec;
    std::list<int> lst;
    int i;

    while (std::cin >> i)
        lst.push_back(i);
    copy(lst.begin(), lst.end(), back_inserter(vec));

    for (auto i : vec)
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}
