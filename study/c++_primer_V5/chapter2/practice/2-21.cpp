/*======================================================================
*        filename: 2-21.cpp
*        author: rambogui
*        data: 2018-12-18 14:30:01
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 0;
    
    //double *dp = &i;
    //int *ip = (int*)i;
    int *p = &i;

    double d = 3.14;

    std::cout << *((int*)&d) << std::endl;
    std::cout << d << std::endl;
        
    return 0;
}
