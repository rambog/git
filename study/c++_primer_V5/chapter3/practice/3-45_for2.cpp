/*======================================================================
*        filename: 3-43_rangefor.cpp
*        author: rambogui
*        data: 2018-12-20 08:47:38
======================================================================*/

#include <iostream>

constexpr int colCnt = 4;
constexpr int rowCnt = 5;

int array[colCnt][rowCnt] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20}
};

int main(int argc, char *argv[])
{
    for (auto row = array; row <= &(array[3]); ++row) {
        for (auto col = *row; col <= &((*row)[4]); ++col)
            std::cout << *col << ' ';
        std::cout << std::endl;
    }
    return 0;
}
