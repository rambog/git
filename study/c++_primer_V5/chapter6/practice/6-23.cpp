/*======================================================================
*        filename: 6-23.cpp
*        author: rambogui
*        data: 2018-12-21 13:31:06
======================================================================*/

#include <iostream>

void print(const int* p, int n)
{
    int idx = 0;
    while (idx != n)
        std::cout << p[idx++] << ' ';
    std::cout << std::endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
        std::cout << *beg++ << ' ';
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    int i = 0;
    int j[2] = {0, 1};

    print(&i, 1);
    print(j , 2);

    //print(std::begin(&i), std::end(&i));
    print(std::begin((int (*)[])(&i)), std::end((int (*)[])(&i)));
    print(std::begin(j), std::end(j));

    return 0;
}
