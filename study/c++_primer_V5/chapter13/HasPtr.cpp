/*======================================================================
*        filename: HasPtr.cpp
*        author: rambogui
*        data: 2019-01-07 10:08:29
======================================================================*/

#include <iostream>
#include <string>

class HasPtr {
private:
    std::string *ps;
    int i;
public:
    HasPtr(const std::string &s = std::string()) : 
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &rhp) :
        ps(new std::string(*rhp.ps)), i(rhp.i) { }
    HasPtr &operator= (const HasPtr &);
    ~HasPtr() { delete ps; }

    friend std::ostream &operator<< (std::ostream &os, const HasPtr &rhp);
};

HasPtr &HasPtr::operator= (const HasPtr &rhp)
{
    std::string *tmp = new std::string(*rhp.ps);
    if (ps) delete ps;
    ps = tmp;
    i = rhp.i;

    return *this;
}

std::ostream &operator<< (std::ostream &os, const HasPtr &rhp)
{
    os << *(rhp.ps);
    return os;
}

HasPtr f(HasPtr hp)
{
    //HasPtr ret = hp;
    HasPtr ret;
    ret = hp;
    return ret;
}

int main(int argc, char *argv[])
{
    HasPtr hp(std::string("rambo"));
    hp = hp;
    std::cout << hp << std::endl;
    return 0;
}
