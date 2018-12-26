/*======================================================================
*        filename: 9-5.cpp
*        author: rambogui
*        data: 2018-12-25 16:55:20
======================================================================*/

#include <iostream>
#include <vector>

std::vector<int>::const_iterator
find(std::vector<int>::const_iterator beg,
        std::vector<int>::const_iterator end, int target)
{
    while (beg != end)
        if (*beg == target)
            break;
        else
            ++beg;

    return beg;
}

int main(int argc, char *argv[])
{
    int temp;
    std::vector<int> ivec;

    while (std::cin >> temp)
        ivec.push_back(temp);

    std::cin.clear();
    std::cin >> temp;

    auto target_iter = find(ivec.begin(), ivec.end(), temp);
    if (target_iter == ivec.end())
        std::cout << "not't find\n";
    else
        std::cout << "find :" << *target_iter << std::endl;

    return 0;
}
