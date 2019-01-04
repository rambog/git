/*======================================================================
*        filename: pair_return.cpp
*        author: rambogui
*        data: 2019-01-04 13:43:40
======================================================================*/

#include <iostream>
#include <utility>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::pair;

using std::endl;
using std::cout;
using std::cin;

pair<string, int>
process(vector<string> &v)
{
    if (!v.empty())
        return {v.back(), v.back().size()};
    else
        return pair<string, int>();
}

int main(int argc, char *argv[])
{

    return 0;
}
