/*======================================================================
*        filename: 3-23.cpp
*        author: rambogui
*        data: 2018-12-19 15:40:50
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec;
    int temp;

    while (std::cin >> temp)
        ivec.push_back(temp);

    std::vector<int>::iterator iter;

    for (iter = ivec.begin(); iter != ivec.end(); ++iter)
        *iter = (*iter)*(*iter);
    for (iter = ivec.begin(); iter != ivec.end(); ++iter)
        std::cout << *iter << ' ' ;
    std::cout << std::endl;

    return 0;
}
