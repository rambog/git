/*======================================================================
*        filename: map_iterator.cpp
*        author: rambogui
*        data: 2019-01-04 10:07:48
======================================================================*/

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using std::string;
using std::map;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    map<string, string> ssmap = {{"gui1", "yao"},
                                 {"gui2", "bingsheng"},
                                 {"gui3", "yuanfen"}};
    map<string, string>::iterator iter = ssmap.begin();
    while (iter != ssmap.end()) {
        cout << iter->first << iter->second << ' ';
        iter++;
    }
    cout << endl;

    for_each(ssmap.cbegin(), ssmap.cend(),
        [](const std::pair<string, string> &p) -> void
        { cout << p.first << p.second << " "; });
    cout << endl;

    return 0;
}
