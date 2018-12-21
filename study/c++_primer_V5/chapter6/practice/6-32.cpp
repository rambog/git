/*======================================================================
*        filename: 6-32.cpp
*        author: rambogui
*        data: 2018-12-21 15:53:08
======================================================================*/

#include <iostream>

int &get(int *array, int index) { return array[index]; }

int main(int argc, char *argv[])
{
    int ia[10] = {0x00};
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;

    for (auto i : ia)
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}
