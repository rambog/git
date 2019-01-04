/*======================================================================
*        filename: 11-11.cpp
*        author: rambogui
*        data: 2019-01-04 11:30:02
======================================================================*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::map;

using std::endl;
using std::cout;
using std::cin;

class Sales_data {
private:
    string strisbn;
public:
    Sales_data(const string &s) : strisbn(s) {}
    Sales_data(const char *cs) : strisbn(cs) {}
    const string &isbn() const { return strisbn; }
};

bool cmpIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main(int argc, char *argv[])
{
    map<Sales_data, string, bool(*)(const Sales_data &, const Sales_data &)> 
        map1(cmpIsbn);
    map1["rambo"] = "guiyao";
    map1["hello"] = "td";
    //{ {"rambo", "guiyao"},{"hello", "td"}};

    for_each(map1.begin(), map1.end(), 
        [](const std::pair<Sales_data, string> &p)
        { cout << p.first.isbn() << p.second << ' '; });
    cout << endl;

    return 0;
}
