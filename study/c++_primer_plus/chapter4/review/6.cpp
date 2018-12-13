/*======================================================================
*        filename: 6.cpp
*        author: rambogui
*        data: 2018-11-27 08:18:20
======================================================================*/

#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    char foo[] = "cheeseburger";

    std::cout << foo << std::endl;
    std::cout << strlen(foo) << " " << sizeof foo << std::endl;

    return 0;
}
