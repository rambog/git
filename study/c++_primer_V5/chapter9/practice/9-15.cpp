/*======================================================================
*        filename: 9-15.cpp
*        author: rambogui
*        data: 2018-12-26 10:45:21
======================================================================*/

#include <iostream>
#include <vector>

using std::vector;

int main(int argc, char *argv[])
{
    vector<int> ivec1 = {1, 2, 4, 5}; 
    vector<int> ivec2 = {1, 2, 4, 5};

    if (ivec1 == ivec2)
        std::cout << "equal" << std::endl;

    return 0;
}
