/*======================================================================
*        filename: privateaccess.cpp
*        author: rambogui
*        data: 2018-12-06 13:21:29
======================================================================*/

#include <iostream>

struct foo
{
private:
    std::string name;
    int money;
public:
    foo(const std::string &s_name, const int n_money);
    void printfothername(const foo &other);
    void show();
};

int main(int argc, char *argv[])
{
    foo f1("rambo", 10);
    foo f2("guiyao", 12);

    f1.show();
    f2.show();

    std::cout << std::endl;
    f1.printfothername(f2);
    f1.printfothername(f1);

    std::cout << std::endl;
    //std::cout << "access from external : " << f1.name << std::endl;

    return 0;
}

foo::foo(const std::string &s_name, const int n_money)
{
    name = s_name;
    money = n_money;
}

void foo::printfothername(const foo &other)
{
    std::cout << "the name is : " << other.name << std::endl;
}

void foo::show()
{
    std::cout << "the name is : " << name << std::endl;
    std::cout << "the money is : " << money << std::endl;
}
