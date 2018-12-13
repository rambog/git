/*======================================================================
*        filename: classconstfunc.cpp
*        author: rambogui
*        data: 2018-12-06 09:43:34
======================================================================*/

#include <iostream>

class foo
{
private:
    std::string name;
    int money;
public:
    foo(const std::string &, const int &);
    void show() const;
};

int main(int argc, char *argv[])
{
    const foo f1("rambo", 100);
    foo f2 = foo("guiyao", 120);
    
    f1.show();
    std::cout << std::endl;
    f2.show();
    return 0;
}

foo::foo(const std::string &sname, const int &nmoney)
{
    name = sname;
    money = nmoney;
}

void foo::show() const
{
    int tmp = 0;
    tmp = 1000;
    std::cout << "Your name: " << name << std::endl;
    std::cout << "You have: " << money << "$\n";
}
