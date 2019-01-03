/*======================================================================
*        filename: 10-17.cpp
*        author: rambogui
*        data: 2019-01-03 09:13:21
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

class Sales_data {
private:
    string isbn;
public:
    Sales_data(const string &s) : 
        isbn(s) { }
    const string &getisbn() const { return isbn; }
};

int main(int argc, char *argv[])
{
    vector<Sales_data> vS;
    Sales_data d("rambo");

    sort(vS.begin(), vS.end(), 
        [](const Sales_data &s1, const Sales_data &s2) -> bool
        { return (s1.getisbn() > s2.getisbn()); });

    return 0;
}
