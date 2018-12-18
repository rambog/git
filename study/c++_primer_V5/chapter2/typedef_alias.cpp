/*======================================================================
*        filename: typedef_alias.cpp
*        author: rambogui
*        data: 2018-12-18 17:16:02
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    typedef double db1;
    using db2 = double;

    db1 d1 = 3.14;
    db2 d2 = 3.14;

    std::cout << d1 << ' ' << d2 << std::endl;

    return 0;
}
