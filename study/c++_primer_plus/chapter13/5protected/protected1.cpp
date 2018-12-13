/*======================================================================
*        filename: protected1.cpp
*        author: rambogui
*        data: 2018-12-12 08:51:54
======================================================================*/

#include <iostream>
#include <string>

class base
{
protected:
    std::string str;
public:
    base(const std::string &str = "base") : str(str) {}
    void show() const;
};

class derive : public base
{
private:
    std::string str;
public:
    derive(const std::string &bstr = "base", const std::string &dstr = "derive") : 
        base(bstr), str(dstr) {}
    void show() const;
};

int main(int argc, char *argv[])
{
    base b;
    derive d;

    b.show();
    d.show();

    return 0;
}

void base::show() const
{
    std::cout << "I am base: ";
    std::cout << "base str->(" << str << ')' << std::endl;
}

void derive::show() const
{
    std::cout << "I am derive:";
    std::cout << " base str->(" << base::str << ") ";
    std::cout << "derive str->(" << str << ')' << std::endl;
}
