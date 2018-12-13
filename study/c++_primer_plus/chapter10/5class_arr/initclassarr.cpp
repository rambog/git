/*======================================================================
*        filename: initclassarr.cpp
*        author: rambogui
*        data: 2018-12-06 11:06:27
======================================================================*/

#include <iostream>

class foo
{
private:
    std::string name;
    int money;
public:
    foo() { }
    foo(const std::string &s_name, const int &n_money);
};

int main(int argc, char *argv[])
{
    const int STKS = 10;

    //(int)STKS = 11;

    foo farr[3] = {
        foo("rambo", 10),
        foo("guiyao", 11),
        //foo("rambogui", 12)
    };

    return 0;
}

foo::foo(const std::string &s_name, const int &n_money)
{
    name = s_name;
    money = n_money;
}
