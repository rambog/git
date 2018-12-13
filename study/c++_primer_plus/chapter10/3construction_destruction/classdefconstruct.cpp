/*======================================================================
*        filename: classdefconstruct.cpp
*        author: rambogui
*        data: 2018-12-06 10:17:08
======================================================================*/

#include <iostream>

class foo
{
private:
    std::string name;
    int money;
public:
    foo();
    void show() const;
};

int main(int argc, char *argv[])
{
    foo f1 = foo();
    f1.show();
    return 0;
}

foo::foo()
{
    name = "rambo";
    money = 100;
}

void foo::show() const
{
    std::cout << "name : " << name << std::endl;
    std::cout << "money : " << money << std::endl;
}
