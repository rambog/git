/*======================================================================
*        filename: pointertopointer.cpp
*        author: rambogui
*        data: 2018-12-18 14:41:10
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;

    std::cout << ival << ' ' << &ival << std::endl;
    std::cout << &pi << ' ' << pi << ' ' << *pi << std::endl;
    std::cout << &ppi << ' ' << ppi << ' ' << *ppi << ' ' << **ppi << std::endl;

    std::cout << std::endl;
    std::cout << "The value of ival\n"
              << "direct value: " << ival << "\n"
              << "indirect value: " << *pi << "\n"
              << "doubly indirect value: " << **ppi << std::endl;

    return 0;
}
