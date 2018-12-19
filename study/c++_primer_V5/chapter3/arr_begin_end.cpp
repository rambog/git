/*======================================================================
*        filename: arr_begin_end.cpp
*        author: rambogui
*        data: 2018-12-19 16:58:10
======================================================================*/

#include <iostream>
#include <iterator>

int main(int argc, char *argv[])
{
    int ia[10];
    double id[10];

    int *ib = std::begin(ia);
    int *ie = std::end(ia);

    double *db = std::begin(id);
    double *de = std::end(id);

    std::cout << ie-ib << ' ' << ie << ' ' << ib << std::endl;
    std::cout << de-db << ' ' << de << ' ' << db << std::endl;

    return 0;
}
