/*======================================================================
*        filename: 11-15.cpp
*        author: rambogui
*        data: 2019-01-04 14:41:54
======================================================================*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using std::map;
using std::pair;
using std::string;
using std::vector;

int main(int argc, char *argv[])
{
    map<int, vector<int>> ivmap;
    ivmap[1] = {1,2,3,4,5,6,7,8,9};

    map<int, vector<int>>::mapped_type
        maptype = ivmap.begin()->second;
    map<int, vector<int>>::key_type
        keytype = ivmap.begin()->first;
    map<int, vector<int>>::value_type
        valtype = *(ivmap.begin());

    return 0;
}
