/*======================================================================
*        filename: container_init3.cpp
*        author: rambogui
*        data: 2018-12-26 09:14:42
======================================================================*/

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class foo {
private:
    string name; 
    string address;
public:
    foo(const string &str1, const string &str2) :
        name(str1), address(str2) { }

friend ostream &operator<< (ostream &os, const foo &f);
};

ostream &operator<< (ostream &os, const foo &f)
{
    os << f.name << ' ' << f.address;
    return os;
}

int main(int argc, char *argv[])
{
    vector<foo> fvec(10, {"rambo","guiyao"});

    vector<foo>::const_iterator beg = fvec.begin(),
                                end = fvec.end();
    while (beg != end)
        std::cout << *beg++ << endl;

    return 0;
}
