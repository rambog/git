/*======================================================================
*        filename: 13-30.cpp
*        author: rambogui
*        data: 2019-01-07 13:57:45
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)),
        i(hp.i) { }
    HasPtr& operator=(const HasPtr &);
    bool operator<(const HasPtr &rhp) const
    { return *ps < *rhp.ps; }
    ~HasPtr() { delete ps; }

    void swap(HasPtr &rhp);

private:
    std::string *ps;
    int i;

friend void swap(HasPtr &lhp, HasPtr &rhp);
friend std::ostream &operator<<(std::ostream &os, const HasPtr &hp);
};

void swap(HasPtr &lhp, HasPtr &rhp);

HasPtr& HasPtr::operator=(const HasPtr &rhp)
{
    std::string *tmp = new std::string(*rhp.ps);
    if (ps) delete ps;
    ps = tmp;
    i = rhp.i;
    return *this;
}

void HasPtr::swap(HasPtr &rhp)
{
    ::swap(*this, rhp);
}

void swap(HasPtr &lhp, HasPtr &rhp)
{
    using std::swap;
    std::cout << "self define swap\n";
    swap(lhp.ps, rhp.ps);
    swap(lhp.i, rhp.i);
}

std::ostream &operator<<(std::ostream &os, const HasPtr &hp)
{
    os << *hp.ps;
    return os;
}

int main(int argc, char *argv[])
{
    std::vector<HasPtr> vhp = { std::string("rambo"),
                                std::string("guiyao"),
                                std::string("hello"),
                                std::string("wori") };

    sort(vhp.begin(), vhp.end());
    for_each(vhp.begin(), vhp.end(), [](const HasPtr &hp) -> void
                                    { std::cout << hp << ' '; });
    std::cout << std::endl;

    return 0;
}
