/*======================================================================
*        filename: 10-21.cpp
*        author: rambogui
*        data: 2019-01-03 10:46:16
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int tmp = 5;

    auto flambda = [&tmp]() -> bool
                    { return --tmp; };

    while (flambda())
        std::cout << "tmp: " << tmp << std::endl;

    return 0;
}
