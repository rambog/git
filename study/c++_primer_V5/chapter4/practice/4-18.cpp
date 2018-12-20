/*======================================================================
*        filename: 4-18.cpp
*        author: rambogui
*        data: 2018-12-20 13:33:17
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec(10, 5);

    std::vector<int>::const_iterator citer;

    citer = ivec.cbegin();
    while (citer != ivec.cend())
        //std::cout << *citer++ << ' ';
        std::cout << *++citer << ' ';
    std::cout << std::endl;

    return 0;
}
