/*======================================================================
*        filename: classlistinit.cpp
*        author: rambogui
*        data: 2018-12-06 09:31:14
======================================================================*/

#include <iostream>

class foo
{
private:
    std::string name;
    int money;
public:
    foo();
    foo(const std::string &, int);
    void show();
};

int main(int argc, char *argv[])
{
    foo f = {"rambo", 10};
    f.show();
    return 0;
}

foo::foo()
{
    
}

foo::foo(const std::string &sname, int nint)
{
    name = sname;
    money = nint;
}

void foo::show()
{
    std::cout << "Your name: " << name << std::endl;
    std::cout << "Your have: " << money << "$\n";
}
