/*======================================================================
*        filename: local_static_object.cpp
*        author: rambogui
*        data: 2018-12-21 09:06:40
======================================================================*/

#include <iostream>
#include <cstddef>

size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}

int main(int argc, char *argv[])
{
    for (size_t i = 0; i != 10; ++i)
        std::cout << count_calls() << std::endl;
    return 0;
}
