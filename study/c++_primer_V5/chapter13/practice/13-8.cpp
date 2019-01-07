/*======================================================================
*        filename: 13.8.cpp
*        author: rambogui
*        data: 2019-01-07 09:35:18
======================================================================*/

#include <iostream>
#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string (s)), i(0) { }
    HasPtr(const HasPtr &rhp) :
        ps(new std::string(*rhp.ps)), i(rhp.i) { }
    HasPtr &operator= (const HasPtr &rhp);
private:
    std::string *ps;
    int i;
};

HasPtr &HasPtr::operator= (const HasPtr &rhp)
{
    if (!ps) {
        delete ps;
        ps = new std::string(*rhp.ps);
        i = rhp.i;
    }
    return *this;
}

int main(int argc, char *argv[])
{

    return 0;
}
