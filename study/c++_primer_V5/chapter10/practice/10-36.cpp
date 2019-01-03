/*======================================================================
*        filename: 10-36.cpp
*        author: rambogui
*        data: 2019-01-03 17:07:55
======================================================================*/

#include <iostream>
#include <list>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::list<int> ilst = {1,2,3,0,4,5,6,0,7,8,9,0,10,11,12};

    auto riter = find(ilst.crbegin(), ilst.crend(), 0);
    std::cout << *riter << std::endl;
    std::cout << *(riter.base()) << std::endl;

    return 0;
}
