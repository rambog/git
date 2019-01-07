/*======================================================================
*        filename: deleted_function.cpp
*        author: rambogui
*        data: 2019-01-07 10:40:53
======================================================================*/

#include <iostream>

class NoCopy {
public:
    NoCopy() = default;
    NoCopy(const NoCopy &) = delete;
    NoCopy &operator=(const NoCopy &) = delete;
    ~NoCopy() = default;
};

void foo(NoCopy n)
{

}

int main(int argc, char *argv[])
{
    NoCopy n1, n2;
    //foo(n);
    n1 = n2;
    return 0;
}
