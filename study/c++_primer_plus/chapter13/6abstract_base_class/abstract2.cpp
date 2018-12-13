/*======================================================================
*        filename: abstract1.cpp
*        author: rambogui
*        data: 2018-12-12 09:28:39
======================================================================*/

#include <iostream>
#include <string>

class base
{
protected:
    std::string str;
public:
    base(const std::string &str = "base") : str(str) {}
    virtual void show1() const = 0;
};

class derive : public base
{
protected:
    std::string str;
public:
    derive(const std::string &bstr = "base", const std::string &dstr = "derive") :
        base(bstr), str(dstr) {}
    void show1() const { std::cout << "I am derive\n"; }
};

class derivederive : public derive
{
protected:
    std:: string str;
public:
    derivederive(const derive &d, const std::string &str) :
        derive(d), str(str) {}
    void show1() const; 
};

int main(int argc, char *argv[])
{
    //base b;
    derive d("rambo", "guiyao");
    derivederive dd(d, "derivederive");
    base *pb;

    derive* pd;
    pd = &d; pd->show1();
    pd = &dd; pd->show1();
    pb = &dd;
    pb->show1();

    return 0;
}

void base::show1() const
{
    std::cout << "I am base\n";
}

void derivederive::show1() const
{
    std::cout << base::str << ' ' << derive::str << ' ' << str << std::endl;
}
