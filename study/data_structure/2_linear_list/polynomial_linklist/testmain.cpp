/*======================================================================
*        filename: testmain.cpp
*        author: rambogui
*        data: 2019-01-17 09:17:27
======================================================================*/

#include <iostream>
#include "polynomial.h"

int main(int argc, char *argv[])
{
    polynomial p1({polynomial::term(1,2),
                polynomial::term(2,3),
                polynomial::term(3,8),
                polynomial::term(10,12),
                });
    
    polynomial p2({
                polynomial::term(2,0),
                polynomial::term(2,2),
                polynomial::term(7,3),
                polynomial::term(2,5),
                polynomial::term(3,13),
                polynomial::term(1,14)
                });

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << (p1*p2) << std::endl;
    std::cout << p1+p2 << std::endl;
    
#if 0
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << std::endl << "+:\n";
    std::cout << p1+p2 << std::endl;
    std::cout << std::endl << "*:\n";
    std::cout << p1*(polynomial::term(1,-3)) << std::endl;

    std::cout <<"================================\n";
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << "p2*p2:";
    std::cout << std::endl << p1*p2 << std::endl << std::endl;

    std::cout << (p2+= p1) << std::endl;


    polynomial p3;
    p3.insert(polynomial::term(1,2));
    p3.insert(polynomial::term(1,3));
    p3.insert(polynomial::term(4,8));
    p3.insert(polynomial::term(9,5));
    std::cout << p3 << std::endl;

    return 0;
#endif
}
