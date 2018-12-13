/*======================================================================
*        filename: class_self.cpp
*        author: rambogui
*        data: 2018-12-10 08:06:11
======================================================================*/

#include <iostream>

class foo
{
private:
    static foo f1;
    static int num;
    int f2;
    int f3;
public:
    foo() {}
    ~foo() {}
    void show();
    friend foo operator+ (const foo &, const foo &);
};

int foo::num = 10;

int main(int argc, char *argv[])
{
    foo f;
    f.show();
    return 0;
}

void foo::show()
{
    std::cout << "num: " << num << std::endl;
}

