/*======================================================================
*        filename: template.cpp
*        author: rambogui
*        data: 2018-12-01 13:52:05
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{

    return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
