/*======================================================================
*        filename: abstract1.cpp
*        author: rambogui
*        data: 2018-12-12 09:28:39
======================================================================*/

#include <iostream>
#include <string>

class base
{
private:
    std::string str;
public:
    base(const std::string &str = "base") : str(str) {}
    virtual void show1() const = 0;
};

class derive : public base
{
private:
    std::string str;
public:
    derive(const std::string &bstr = "base", const std::string &dstr = "derive") :
        base(bstr), str(dstr) {}
    //void show1() const { std::cout << "I am derive\n"; }
};

int main(int argc, char *argv[])
{
    //base b;
    derive d;
    d.show1();
    return 0;
}

void base::show1() const
{
    std::cout << "I am base\n";
}
