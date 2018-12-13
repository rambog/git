/*======================================================================
*        filename: basetype.cpp
*        author: rambogui
*        data: 2018-12-04 10:52:06
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int *p = new int[10]  {1, 2, 3};

    for (int i = 0; i < 10; i++)
        std::cout << p[i] << ' ';
    std::cout << std::endl;

    return 0;
}
