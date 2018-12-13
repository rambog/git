/*======================================================================
*        filename: decltype_func.cpp
*        author: rambogui
*        data: 2018-12-01 16:42:10
======================================================================*/

#include <iostream>

int func(int &a)
{
    return a++;
}

int main(int argc, char *argv[])
{
    int tmp = 10;
    decltype(func(tmp)) a = func(tmp);

    std::cout << tmp << ' ' << a << std::endl;
        
    return 0;
}
