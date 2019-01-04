/*======================================================================
*        filename: multimap_iterator.cpp
*        author: rambogui
*        data: 2019-01-04 10:31:59
======================================================================*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using std::multimap;
using std::string;
using std::vector;
using std::pair;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    vector<pair<string, string>> pv = {
        {"gui", "yao"}, {"gui", "bingsheng"}, {"gui", "yuanfen"}};
    multimap<string, string> ssmlmap(pv.begin(), pv.end());

    for_each(ssmlmap.begin(), ssmlmap.end(),
        [](const pair<string, string> &sp)
        { cout << sp.first << sp.second << ' ';});
    cout << endl;

    multimap<string, string>::iterator iter = ssmlmap.begin();
    while (iter != ssmlmap.end()) {
        cout << iter->first << iter->second << ' ';
        ++iter;
    }
    cout << endl;

    return 0;
}
