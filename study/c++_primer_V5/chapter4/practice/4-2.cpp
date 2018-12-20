/*======================================================================
*        filename: 4-2.cpp
*        author: rambogui
*        data: 2018-12-20 10:26:17
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec (10, 1);

    std::cout << ivec.size() << std::endl;
    std::cout << *ivec.begin() << std::endl;

    return 0;
}
