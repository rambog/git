/*======================================================================
*        filename: 11-4.cpp
*        author: rambogui
*        data: 2019-01-04 09:00:30
======================================================================*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::map;
using std::set;
using std::pair;

bool cmp2str(const string &str1, const string &str2)
{
    string::size_type idx;
    for (idx = 0; idx < str1.size() && idx < str2.size(); ++idx)
        if (toupper(str1[idx]) != toupper(str2[idx]))
            return false;

    for ( ; idx < str1.size(); ++idx)
        if (!ispunct(str1[idx]))
            return false;

    for ( ; idx < str2.size(); ++idx)
        if (!ispunct(str2[idx]))
            return false;

    return true;
}

void formatstr(string &str)
{
    string::size_type idx;
    for (idx = 0; idx < str.size(); ++idx) {
        if (isupper(str[idx]))
            str[idx] = tolower(str[idx]);
        if (ispunct(str[idx]))
            break;
    }
    str.resize(idx);
}

int main(int argc, char *argv[])
{
    map<string, size_t> word_count;
    string word;

    while (cin >> word) {
        formatstr(word);
        ++word_count[word];
    }

    for (const pair<string, size_t> &w : word_count)
        cout << w.first << " occur " << w.second
             << (w.second > 1 ? " times" : " time") << endl;

    return 0;
}
