/*======================================================================
*        filename: iterator_sizeof.cpp
*        author: rambogui
*        data: 2018-12-19 14:36:28
======================================================================*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    std::string s; 
    std::vector<std::string> svec;
    std::vector<int> ivec;

    auto s_iter = s.begin();
    auto sv_iter = svec.begin();
    auto iv_iter = ivec.begin();

    std::cout << "sizeof string_iterator: " << sizeof s_iter << std::endl;
    std::cout << "sizeof string_vector_iterator: " << sizeof sv_iter << std::endl;
    std::cout << "sizeof string_int_iterator: " << sizeof iv_iter << std::endl;

    return 0;
}
