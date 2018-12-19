/*======================================================================
*        filename: vector_idx.cpp
*        author: rambogui
*        data: 2018-12-19 13:34:14
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> score(11, 0);

    std::vector<int>::size_type tmp = 0;

    while (std::cin >> tmp)
        if (tmp/10 < 11)
            score[tmp/10]++;

    for (auto i : score)
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}
