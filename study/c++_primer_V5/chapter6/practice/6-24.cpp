/*======================================================================
*        filename: 6-24.cpp
*        author: rambogui
*        data: 2018-12-21 13:50:47
======================================================================*/

#include <iostream>

void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        std::cout << ia[i] << std::endl;
}

int main(int argc, char *argv[])
{
    int a[5] = {1, 2, 3, 4, 5};

    print(a);

    return 0;
}
