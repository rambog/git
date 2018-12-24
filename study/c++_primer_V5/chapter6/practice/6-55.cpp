/*======================================================================
*        filename: 6-54.cpp
*        author: rambogui
*        data: 2018-12-22 10:25:29
======================================================================*/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int add(int i1, int i2)
{
    std::cout << i1 << " add " << i2 << " is " << i1+i2 << std::endl;
}

int substract(int i1, int i2)
{
    std::cout << i1 << " substract " << i2 << " is " << i1-i2 << std::endl;
}

int multiply(int i1, int i2)
{
    std::cout << i1 << " multiply " << i2 << " is " << i1*i2 << std::endl;
}

int divide(int i1, int i2)
{
    std::cout << i1 << " divide " << i2 << " is " << i1/i2 << std::endl;
}

int main(int argc, char *argv[])
{
    std::vector<int(*)(int,int)> pfvector = {add, substract, multiply, divide};

    int i1, i2;

    while (cin >> i1 >> i2) {
        std::vector<int(*)(int, int)>::const_iterator citer = pfvector.begin();
        for ( ;citer != pfvector.end(); ++citer)
            (*citer)(i1, i2);
    }

    return 0;
}
