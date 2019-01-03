/*======================================================================
*        filename: 10-35.cpp
*        author: rambogui
*        data: 2019-01-03 17:04:50
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> iv = {1,2,3,4,5,6,7,8,9};

    for (std::vector<int>::const_iterator citer = iv.end()-1;
        citer != iv.begin()-1; --citer)
        std::cout << *citer << ' ';
    std::cout << std::endl;

    return 0;
}
