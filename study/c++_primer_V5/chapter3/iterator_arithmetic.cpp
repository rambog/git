/*======================================================================
*        filename: iterator_arithmetic.cpp
*        author: rambogui
*        data: 2018-12-19 15:48:39
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec(10, 9);

    std::vector<int>::iterator iter;
    iter = ivec.begin();
    iter--;

    std::cout << (ivec.begin() - iter) << std::endl;

    return 0;
}
