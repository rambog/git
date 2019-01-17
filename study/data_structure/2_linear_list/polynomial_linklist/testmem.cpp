/*======================================================================
*        filename: testmem.cpp
*        author: rambogui
*        data: 2019-01-17 13:26:37
======================================================================*/

#include <iostream>
#include "polynomial.h"

int main(int argc, char *argv[])
{
    polynomial *p = nullptr;
    while (true) {
        p = new polynomial({
            polynomial::term(1,2),
            polynomial::term(1,3),
            polynomial::term(1,4),
            polynomial::term(1,5),
            polynomial::term(1,6),
            polynomial::term(1,7),
            polynomial::term(1,8),
            });
        delete p;
    }
    return 0;
}
