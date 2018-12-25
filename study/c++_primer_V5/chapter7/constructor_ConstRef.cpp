/*======================================================================
*        filename: constructor_ConstRef.cpp
*        author: rambogui
*        data: 2018-12-25 10:07:42
======================================================================*/

#include <iostream>

#if 0
class ConstRef {
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
};

ConstRef::ConstRef(int ii)
{
    i = ii;
    ci = ii;
    ri = i;
}
#else
class ConstRef {
public:
    ConstRef(int ii) : i(ii), ci(ii), ri(i) { }
public:
    int i;
    const int ci;
    int &ri;
};
#endif

int main(int argc, char *argv[])
{
    ConstRef cr(10);
    std::cout << sizeof cr << std::endl;
    std::cout << &cr << std::endl;
    std::cout << &(cr.i) << ' ' << &(cr.ci) << ' ' << &(cr.ri) << std::endl;
    return 0;
}
