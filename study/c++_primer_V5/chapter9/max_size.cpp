/*======================================================================
*        filename: max_size.cpp
*        author: rambogui
*        data: 2018-12-26 10:35:26
======================================================================*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    std::string str;
    std::vector<int> ivec;
    std::vector<std::vector<int> > vvec;

    std::cout << str.max_size() << std::endl;
    std::cout << ivec.max_size() << std::endl;
    std::cout << vvec.max_size() << std::endl;

    return 0;
}
