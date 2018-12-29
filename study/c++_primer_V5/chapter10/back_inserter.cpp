/*======================================================================
*        filename: back_inserter.cpp
*        author: rambogui
*        data: 2018-12-29 09:48:38
======================================================================*/

#include <iostream>
#include <vector>
#include <iterator>

int main(int argc, char *argv[])
{
    std::vector<int> iv = {1,2,3,4,5};
    fill_n(back_inserter(iv), 10, 100);

    for (int tmp : iv)
        std::cout << tmp << ' ';
    std::cout << std::endl;

    return 0;
}
