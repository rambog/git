/*======================================================================
*        filename: testmain.cpp
*        author: rambogui
*        data: 2019-01-16 11:16:53
======================================================================*/

#include <iostream>
#include "slinklist.h"

int main(int argc, char *argv[])
{
    slinklist sl({1,2,3,4,5,6,7,8,9,10,11,12,13,14});

    std::cout << sl << std::endl;

    std::cout << sl.locate_elem(8, compare) << std::endl;
    std::cout << sl.locate_elem(-8, compare) << std::endl;

    std::cout << "insert delete test!\n";
    std::cout << sl.total_length() << ' ' << sl.length() << std::endl;
    sl.insert(0, -1);
    sl.insert(6, 99);
    sl.insert(sl.length(), 88);
    std::cout << sl << std::endl;
    std::cout << sl.total_length() << ' ' << sl.length() << std::endl;

    slinklist::elemtype tmp;
    sl.delelem(0, tmp);
    sl.insert(0,111);
    sl.delelem(0, tmp);
    sl.insert(0,1111);
    sl.delelem(0, tmp);
    sl.insert(0,81);
    sl.delelem(0, tmp);
    sl.insert(0,88);

    std::cout << sl << std::endl;
    std::cout << sl.total_length() << ' ' << sl.length() << std::endl;
    std::cout << tmp << std::endl;

    std::cout << "push back\n";
    slinklist sl1;
    sl1.push_back(1);
    sl1.delelem(0,tmp);
    sl1.push_back({5,6,7,8,9});
    std::cout << sl1 << std::endl;
    
    return 0;
}
