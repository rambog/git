/*======================================================================
*        filename: virtual_funcinherit.cpp
*        author: rambogui
*        data: 2018-12-11 14:00:26
======================================================================*/

#include <string>
#include <iostream>

class baseclass
{
private:
    std::string str;
public:
    baseclass(const std::string &str = "baseclass");
    void show1();
    virtual void show2();
};

class deriveclass : public baseclass
{
private:
    std::string str;
public:
    deriveclass(const std::string &bstr = "baseclass", 
        const std::string &dstr= "deriveclass"); 
    void show1();
    virtual void show2();
};

int main(int argc, char *argv[])
{
    baseclass b1("rambo");
    deriveclass d1("rambogui", "guiyao");

    baseclass &refb1 = d1;
    deriveclass &refb2 = d1;

    refb1.show1();
    refb2.show1();
    refb1.show2();
    refb2.show2();

    std::cout << std::endl;

    deriveclass *pdcls = (deriveclass*)(&b1);
    pdcls->show1();
    pdcls->show2();

    pdcls = &d1;
    pdcls->show1();
    pdcls->show2();

    return 0;
}

baseclass::baseclass(const std::string &str) : str(str)
{

}

void baseclass::show1()
{
    std::cout << "I am baseclass show1: " << str << std::endl;
}

void baseclass::show2()
{
    std::cout << "I am baseclass virtual show2: " << str << std::endl;
}

deriveclass::deriveclass(const std::string &bstr, const std::string &dstr) :
    baseclass(bstr), str(dstr)
{

}

void deriveclass::show1()
{
    std::cout << "I am deriveclass show1: " << str << std::endl;
}

void deriveclass::show2()
{
    std::cout << "I am deriveclass virtual show2: " << str << std::endl;
}
