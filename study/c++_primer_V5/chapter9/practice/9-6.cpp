/*======================================================================
*        filename: 9-6.cpp
*        author: rambogui
*        data: 2018-12-26 08:17:57
======================================================================*/

#include <iostream>
#include <list>

int main(int argc, char *argv[])
{
    std::list<int> lst1;
    std::list<int>::iterator iter1 = lst1.begin(),
        iter2 = lst1.end();

    //while (iter1 < iter2)
    while (iter1 != iter2)
        ;

    return 0;
}
