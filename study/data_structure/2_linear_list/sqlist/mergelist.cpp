/*======================================================================
*        filename: mergelist.cpp
*        author: rambogui
*        data: 2019-01-15 13:27:04
======================================================================*/

#include <iostream>
#include "sqlist.h"

void mergelist(sqlist la, sqlist lb, sqlist &lc)
{
    int i = 0, j = 0; 
    ElemType tmpa, tmpb;

    while (i < la.length() && j < lb.length()) {
        la.get_elem(i, tmpa);
        lb.get_elem(j, tmpb);

        if (tmpa < tmpb) {
            lc.insert(lc.length(), tmpa);
            i++;
        } else {
            lc.insert(lc.length(), tmpb);
            j++;
        }
    }

    while (i < la.length()) {
        la.get_elem(i++, tmpa);
        lc.insert(lc.length(), tmpa);
    }

    while (j < lb.length()) {
        lb.get_elem(j++, tmpb);
        lc.insert(lc.length(), tmpb);
    }
}

int main(int argc, char *argv[])
{
    sqlist la({1,3,5,8,11,23,44,49,52,69,77,81});
    sqlist lb({2,5,7,13,17,33,37,50,55,77,79,83,100,111});
    sqlist lc;

    mergelist(la, lb, lc);

    std::cout << la << std::endl;
    std::cout << lb << std::endl;
    std::cout << lc << std::endl;

    return 0;
}
