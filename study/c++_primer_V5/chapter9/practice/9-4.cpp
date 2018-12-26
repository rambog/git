/*======================================================================
*        filename: 9-4.cpp
*        author: rambogui
*        data: 2018-12-25 16:47:59
======================================================================*/

#include <iostream>
#include <vector>

bool find_vector(std::vector<int>::const_iterator beg,
        std::vector<int>::const_iterator end, int target)
{
    while (beg != end)
        if (*beg++ == target)
            return true;
}

int main(int argc, char *argv[])
{
    std::vector<int> ivec;
    int temp;

    while (std::cin >> temp) 
        ivec.push_back(temp);

    std::cin.clear();
    std::cin >> temp;

    if (find_vector(ivec.begin(), ivec.end(), temp))
        std::cout << "find target: " << temp << std::endl;

    return 0;
}
