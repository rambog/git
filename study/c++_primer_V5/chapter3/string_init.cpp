/*======================================================================
*        filename: string_init.cpp
*        author: rambogui
*        data: 2018-12-19 08:40:18
======================================================================*/

#include <iostream>
#include <string>
#include <cstring>
using std::string;

int main(int argc, char *argv[])
{
    string v("rambo");

    std::cout << sizeof("rambo") << std::endl;
    std::cout << std::strlen("rambo") << std::endl;
    std::cout << v.size() << std::endl;

    string v2(10, 'r');
    std::cout << v2.size() << ' ' << sizeof v2 << std::endl;
    std::cout << v2 << std::endl;

    std::cout << sizeof(string) << std::endl;
    std::cout << sizeof(void*) << std::endl;

    return 0;
}
