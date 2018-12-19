/*======================================================================
*        filename: vector_sizetype.cpp
*        author: rambogui
*        data: 2018-12-19 13:30:34
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::cout << "sizeof vector<int>::size_type: "
              << sizeof(std::vector<int>::size_type) << std::endl;
    return 0;
}
