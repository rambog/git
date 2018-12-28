/*======================================================================
*        filename: at.cpp
*        author: rambogui
*        data: 2018-12-27 08:46:02
======================================================================*/

#include <iostream>
#include <vector>
#include <list>

using std::list;
using std::vector;

int main(int argc, char *argv[])
{
    vector<int> ivec(10, 10); 
    list<int> ilst(10, 11);

    ivec[0];
    //ivec.at(9);
    ivec.at(91);

    ilst[0];
    ilst.at[2];

    return 0;
}
