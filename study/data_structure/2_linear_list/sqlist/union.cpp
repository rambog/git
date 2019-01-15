/*======================================================================
*        filename: union.cpp
*        author: rambogui
*        data: 2019-01-15 11:32:55
======================================================================*/

#include <iostream>
#include "sqlist.h"

void Union(sqlist &la, sqlist lb) 
{
    sqlist::qsize lb_len = lb.length();
    ElemType tmp;

    for (int i = 0; i < lb_len; ++i) {
        lb.get_elem(i, tmp);
        if (la.locate_elem(tmp) < 0)
            la.insert(la.length(), tmp);
    }
}

int main(int argc, char *argv[])
{
    sqlist la({1,2,3,5,7,8,10,29});
    sqlist lb({2,5,88,90,100,900,1000});

    std::cout << la << std::endl;
    std::cout << lb << std::endl;

    Union(la, lb);

    std::cout << la << std::endl;
    std::cout << lb << std::endl;
    return 0;
}
