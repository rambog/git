/*======================================================================
*        filename: map_iterator2.cpp
*        author: rambogui
*        data: 2019-01-04 14:30:52
======================================================================*/

#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::string;
using std::map;
using std::pair;

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char *argv[])
{
    map<string, string> ssmap;
    ssmap["gui"] = "yao";
    
    map<string, string>::iterator iter = ssmap.begin();

    cout << iter->first << iter->second << endl;

    iter->second = "rambo";
    iter->first = "gui";

    return 0;
}
