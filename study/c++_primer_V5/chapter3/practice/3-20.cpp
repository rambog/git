/*======================================================================
*        filename: 3-20.cpp
*        author: rambogui
*        data: 2018-12-19 14:05:55
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec; 
    int temp;

    while (std::cin >> temp)
        ivec.push_back(temp);

    for (auto i : ivec)
        std::cout << i << ' ';
    std::cout << std::endl;

    std::vector<int>::size_type idx;

    for (idx = 0; idx < ivec.size(); ++idx)
        if (idx < ivec.size()-1)
            std::cout << ivec[idx] + ivec[idx+1] << ' ';
    std::cout << std::endl;

    for (idx = 0; idx < ivec.size(); ++idx)
        std::cout << ivec[idx] + ivec[ivec.size()-idx-1] << ' ';
    std::cout << std::endl;

    return 0;
}
