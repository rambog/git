/*======================================================================
*        filename: 10-22.cpp
*        author: rambogui
*        data: 2019-01-03 13:56:51
======================================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cin;

using namespace std::placeholders;

void printfsv(const string &str, std::ostream &os)
{
    os << str << ' ';
}

bool cmpsize(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

vector<string>::const_iterator
split(const vector<string> &words, string::size_type sz)
{
    return find_if(words.begin(), words.end(), 
                    bind(cmpsize, _1, sz));
}

int main(int argc, char *argv[])
{
    vector<string> words;
    string word;
    while (cin >> word)
        words.push_back(word);

    sort(words.begin(), words.end(), 
        [](const string &s1, const string &s2) -> bool
        { return s1.size() < s2.size(); });
    for_each(words.begin(), words.end(), 
        bind(printfsv, _1, ref(cout)));

    cout << *split(words, 6) << std::endl;

    return 0;
}
