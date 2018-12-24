/*======================================================================
*        filename: 6-54.cpp
*        author: rambogui
*        data: 2018-12-22 10:25:29
======================================================================*/

#include <iostream>
#include <vector>

int foo(int i1, int i2)
{
    std::cout << i1 << ' ' << i2 << std::endl;
}

int main(int argc, char *argv[])
{
    std::vector<int(*)(int,int)> pfvector = {foo};

    (*pfvector.begin())(1,2);

    return 0;
}
