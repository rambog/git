/*======================================================================
*        filename: nspce_using.cpp
*        author: rambogui
*        data: 2018-12-03 19:40:40
======================================================================*/

#include <iostream>

namespace //nspc 
{
    double fetch;
}

int foo()
{
    //using namespace nspc;
    //using nspc::fetch;

    fetch++;
}

int main(int argc, char *argv[])
{
    //using namespace nspc;
    //using nspc::fetch;

    fetch++;
    foo();

    std::cout << fetch << std::endl;

    return 0;
}
