/*======================================================================
*        filename: set_cmpfunc.cpp
*        author: rambogui
*        data: 2019-01-04 11:19:24
======================================================================*/

#include <iostream>
#include <set>
#include <string>
#include <map>

using std::set;
using std::multiset;
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::map;

class Sales_data {
private:
    string str_isbn;
public:
    Sales_data(const string &s) : str_isbn(s) {}
    const string &isbn() const { return str_isbn; }
};

bool comparaIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main(int argc, char *argv[])
{
    multiset<Sales_data, decltype(comparaIsbn)*> bookstore(comparaIsbn);    

    map<Sales_data, string, decltype(comparaIsbn)*> bkstor(comparaIsbn);

    return 0;
}
