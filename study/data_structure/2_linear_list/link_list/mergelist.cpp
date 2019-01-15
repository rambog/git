/*======================================================================
*        filename: mergelist.cpp
*        author: rambogui
*        data: 2019-01-15 17:08:11
======================================================================*/

#include <iostream>
#include "linklist.h"

void mergelist(linklist la, linklist lb, linklist &lc) 
{
    const linklist::linknode *pla = la.get_mem();
    const linklist::linknode *plb = lb.get_mem();

    while (pla != nullptr && plb != nullptr) {
        if (pla->data < plb->data) {
            lc.push_back(pla->data);
            pla = pla->next;
        } else {
            lc.push_back(plb->data);
            plb = plb->next;
        }
    }

    while (pla != nullptr) {
        lc.push_back(pla->data);
        pla = pla->next;
    }

    while (plb != nullptr) {
        lc.push_back(plb->data);
        plb = plb->next;
    }
}

int main(int argc, char *argv[])
{
    linklist la({1,3,7,13,16,19,22,26,27,29,30,33,37,39});
    linklist lb({8,14,18,24,39,41,44,47,59,77,88,99,101,999});
    linklist lc;

    mergelist(la, lb, lc);

    std::cout << la << std::endl;
    std::cout << lb << std::endl;
    std::cout << lc << std::endl;

    return 0;
}
