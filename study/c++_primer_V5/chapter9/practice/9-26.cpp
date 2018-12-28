/*======================================================================
*        filename: 9-26.cpp
*        author: rambogui
*        data: 2018-12-27 09:28:51
======================================================================*/

#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    vector<int> ivec(std::begin(ia), std::end(ia));
    list<int> ilst(std::begin(ia), std::end(ia));

    for (auto tmp : ivec)
        std::cout << tmp << ' ';
    std::cout << std::endl;
    for (auto tmp : ilst)
        std::cout << tmp << ' ';
    std::cout << std::endl;

    vector<int>::iterator viter;
    list<int>::iterator liter;

    for (viter = ivec.begin(); viter != ivec.end();)
        if (*viter % 2 == 0)
            viter = ivec.erase(viter);
        else
            ++viter;

    for (liter = ilst.begin(); liter != ilst.end();)
        if (*liter % 2 != 0)
            liter = ilst.erase(liter);
        else
            ++liter;

    for (auto tmp : ivec)
        std::cout << tmp << ' ';
    std::cout << std::endl;
    for (auto tmp : ilst)
        std::cout << tmp << ' ';
    std::cout << std::endl;
    return 0;
}
