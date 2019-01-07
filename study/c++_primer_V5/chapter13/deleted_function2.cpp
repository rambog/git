/*======================================================================
*        filename: deleted_function2.cpp
*        author: rambogui
*        data: 2019-01-07 10:44:25
======================================================================*/

#include <iostream>

class NoDtor {
    NoDtor() = default;
    ~NoDtor() = delete;
};

int main(int argc, char *argv[])
{
    NoDtor *nd;
    nd = new NoDtor;
    return 0;
}
