/*======================================================================
*        filename: 10_auto.cpp
*        author: rambogui
*        data: 2018-11-24 09:16:20
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    auto cars = 15;
    auto iou = 150.37f;
    auto level = 'B';
    auto crat = U'\U00002155';
    auto crat1 = u'\u2155';
    auto crat2 = L'P';
    auto fract = 8.25f/2.5;

    std::cout << sizeof cars << std::endl;
    std::cout << sizeof iou << std::endl;
    std::cout << sizeof level << std::endl;
    std::cout << sizeof crat << std::endl;
    std::cout << sizeof crat1 << std::endl;
    std::cout << sizeof crat2 << std::endl;
    std::cout << sizeof fract << std::endl;

    return 0;
}
