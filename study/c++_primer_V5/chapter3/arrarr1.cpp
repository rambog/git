/*======================================================================
*        filename: arrarr1.cpp
*        author: rambogui
*        data: 2018-12-19 19:36:19
======================================================================*/

#include <iostream>
#include <cstddef>

int main(int argc, char *argv[])
{
    constexpr size_t rowCnt = 3, colCnt = 4;

    int ia[rowCnt][colCnt];

    for (size_t i = 0; i != rowCnt; ++i)
        for (size_t j = 0; j != colCnt; ++j)
            ia[i][j] = i * colCnt + j;
            
    for (size_t i = 0; i != rowCnt; ++i) {
        for (size_t j = 0; j != colCnt; ++j)
            std::cout << ia[i][j] << ' ';
        std::cout << std::endl;
    }

    return 0;
}
