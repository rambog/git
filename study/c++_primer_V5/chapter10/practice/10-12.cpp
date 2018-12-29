/*======================================================================
*        filename: 10-12.cpp
*        author: rambogui
*        data: 2018-12-29 13:56:29
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

class Sales_data {
private:
    string str;
public:
    Sales_data(const string &s) : str(s) {}

friend std::ostream &operator<<(std::ostream &os, const Sales_data &sd);
friend bool operator<(const Sales_data &s1, const Sales_data &s2);
};

std::ostream &operator<<(std::ostream &os, const Sales_data &sd)
{
    os << sd.str;
}

bool operator<(const Sales_data &s1, const Sales_data &s2)
{
    return s1.str < s2.str;
}

int main(int argc, char *argv[])
{
    vector<Sales_data> Sv;
    string tmp;

    while (cin >> tmp) {
        Sv.push_back(tmp);
    }

    for (auto tmp : Sv)
        cout << tmp << ' ';
    cout << endl;

    sort(Sv.begin(), Sv.end());

    for (auto tmp : Sv)
        cout << tmp << ' ';
    cout << endl;

    return 0;
}
