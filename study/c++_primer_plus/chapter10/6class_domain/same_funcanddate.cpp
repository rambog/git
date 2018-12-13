/*======================================================================
*        filename: same_funcanddate.cpp
*        author: rambogui
*        data: 2018-12-06 13:31:33
======================================================================*/

#include <iostream>
#include <string>

std::string name;

void show()
{
    using namespace std;
    cout << "I am global func:" << name << endl;
}

class foo
{
private:
    std::string name;
    int money;
public:
    foo(const std::string &, const int &);
    void show();
    void show2();
};

int main(int argc, char *argv[])
{
    name = "global";

    foo f1("rambo", 10);

    f1.show();
    f1.show2();

    return 0;
}

foo::foo(const std::string &s_name, const int &n_money)
{
    name = s_name;
    money = n_money;
}

void foo::show()
{
    using namespace std;
    cout << "I am class func: " << name;
    cout << " " << money << endl;
}

void foo::show2()
{
    using namespace std;
    cout << "I am show2" << endl;
    cout << "global name: " << ::name << endl;
    show();
}
