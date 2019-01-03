/*======================================================================
*        filename: lambda_static.cpp
*        author: rambogui
*        data: 2019-01-03 08:17:57
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    const int tmp = 1;
    bool (*flambda)(int, int) = [](int i1, int i2) -> bool
                                { return (i1-i2) > tmp; };
    return 0;
}
