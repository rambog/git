/*======================================================================
*        filename: operator_inherit.cpp
*        author: rambogui
*        data: 2018-12-13 15:21:22
======================================================================*/

#include <iostream>
#include <string>

class base
{
private:
    std::string str;
public:
    base(const std::string &str = "base") : str(str) {}
    base operator+ (const base &b);
    //base& operator= (const base &b);
    friend std::ostream& operator<< (std::ostream &os, const base &b);
};

class derive : public base
{
private:
    std::string str;
public:
    derive(const std::string &bstr = "base", const std::string &dstr = "derive") :
        base(bstr), str(dstr) {}
    friend std::ostream& operator<< (std::ostream &os, const derive &d);
};

int main(int argc, char *argv[])
{
    derive d1("base1", "derive1");
    derive d2("base2", "derive2");

    std::cout << d1 << ' ' << d2 << std::endl;

    std::cout << d1+d2 << std::endl;

    std::cout << (d2 = d1) << std::endl;

    return 0;
}

base base::operator+ (const base &b)
{
    return base(this->str+b.str);
}

#if 0
base& base::operator= (const base &b)
{
    if (this == &b) return *this;
    str = b.str;
    return *this;
}
#endif

std::ostream& operator<< (std::ostream &os, const base &b)
{
    os << b.str;
    return os;
}

std::ostream& operator<< (std::ostream &os, const derive &d)
{
    os << (const base&)d;
    os << d.str;
    return os;
}
