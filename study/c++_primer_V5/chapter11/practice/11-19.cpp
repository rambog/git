/*======================================================================
*        filename: 11-19.cpp
*        author: rambogui
*        data: 2019-01-04 15:43:33
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using std::string;
using std::vector;
using std::multiset;
using std::pair;

using std::endl;
using std::cout;
using std::cin;

class Sales_data {
private:
    string str_isbn;
public:
    Sales_data(const string &s = "null") : str_isbn(s) { }
    Sales_data(const char *cs) : str_isbn(cs) {}
    const string &isbn() const { return str_isbn; };
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main(int argc, char *argv[])
{
    multiset<Sales_data, bool(*)(const Sales_data &, const Sales_data &)>
        bookstore(compareIsbn);
    bookstore.insert({"rambo", "guiyao", "hello"});
    Sales_data tmp(*(bookstore.begin()));
    cout << tmp.isbn() << endl;

    return 0;
}
