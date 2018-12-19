/*======================================================================
*        filename: arr_cstyle_cmp.cpp
*        author: rambogui
*        data: 2018-12-19 17:24:50
======================================================================*/

#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    const char ca1[] = "A string example";
    const char ca2[] = "A different string";
    const char *pca1 = "A string example";
    const char *pca2 = "A different string";
    
    std::cout << strcmp(ca1, ca2) << std::endl;
    std::cout << strcmp(ca2, ca1) << std::endl;
    std::cout << (void*)ca1 << ' ' << (void*)ca2 << std::endl;
    std::cout << (void*)pca1 << ' ' << (void*)pca2 << std::endl;

    return 0;
}
