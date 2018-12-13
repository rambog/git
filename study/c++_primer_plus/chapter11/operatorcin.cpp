/*======================================================================
*        filename: operatorcin.cpp
*        author: rambogui
*        data: 2018-12-08 09:35:22
======================================================================*/

#include <iostream>
#include <istream>
#include <ostream>

class foo
{
private:
    int f1;
    int f2;
public:
    foo() { f1 = 0; f2 = 0; }
    foo(const int &f1, const int &f2)
    { this->f1 = f1; this->f2 = f2; }
    
    friend std::ostream& operator<< (std::ostream &os, const foo &f);
    friend std::istream& operator>> (std::istream &is, foo &f);
};

int main(int argc, char *argv[])
{
    foo f1;
    foo f2;

    std::cout << f1 << f2;

    std::cout << std::endl;
    std::cin >> f1 >> f2;
    std::cout << f1 << f2;

    return 0;
}

std::ostream& operator<< (std::ostream &os, const foo &f)
{
    os << "I am friend << ";
    os << f.f1 << ' ' << f.f2 << std::endl;
    return os;
}

std::istream& operator>> (std::istream &is, foo &f)
{
    std::cout << "I am firned >> ";
    is >> f.f1 >> f.f2;
    return is;
}
