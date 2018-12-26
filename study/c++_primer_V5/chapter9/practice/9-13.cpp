/*======================================================================
*        filename: 9-13.cpp
*        author: rambogui
*        data: 2018-12-26 09:44:22
======================================================================*/

#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

int main(int argc, char *argv[])
{
    list<int> ilst = {1, 2, 3, 4, 5, 6};
    vector<double> dvec(ilst.begin(), ilst.end());

    for (double tmp : dvec)
        std::cout << tmp << ' ';
    std::cout << std::endl;

    return 0;
}
