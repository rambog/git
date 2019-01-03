/*======================================================================
*        filename: 10-25.cpp
*        author: rambogui
*        data: 2019-01-03 14:35:56
======================================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;

using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void print(const string &s, std::ostream &os)
{
    os << s << ' ';
}

void biggies(vector<string> &sv, string::size_type sz)
{
    sort(sv.begin(), sv.end());
    auto newend = unique(sv.begin(), sv.end());
    sv.erase(newend, sv.end());
    stable_sort(sv.begin(), sv.end(),
                [](const string &s1, const string &s2)
                { return s1.size() < s2.size(); });
    
    for_each(sv.begin(), sv.end(), [](const string &s)
                                    { cout << s << ' ';});
    cout << endl;

    //std::cout << *partition(sv.begin(), sv.end(), 
                            //bind(check_size, _1, sz)) << std::endl;
}

int main(int argc, char *argv[])
{
    vector<string> words = {"rambo", "guiyao", "hello", "endl", "hello", "baby", "adult",
                            "namespace", "string", "list", "z" ,"world", "zhangtaoxiang",
                            "ramboguiu", "lisuny"};

    biggies(words, 5);

    for_each(words.begin(), words.end(), 
                bind(print, _1, ref(cout)));
    cout << endl;
    return 0;
}
