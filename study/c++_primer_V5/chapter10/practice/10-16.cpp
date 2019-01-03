/*======================================================================
*        filename: 10-16.cpp
*        author: rambogui
*        data: 2019-01-03 09:06:25
======================================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;

void biggies(vector<string> &words,
                vector<string>::size_type sz)
{
    sort(words.begin(), words.end());
    vector<string>::iterator uniend = unique(words.begin(), words.end());
    words.erase(uniend, words.end());
    vector<string>::iterator findit = 
                    find_if(words.begin(), words.end(), [sz](const string &a)
                                                        { return a.size() >= sz; });
    for_each(findit, words.end(), [](const string &s)
                                    { cout << s << ' '; });
    cout << endl;
}

int main(int argc, char *argv[])
{

    return 0;
}
