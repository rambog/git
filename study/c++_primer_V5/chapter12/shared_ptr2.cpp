/*======================================================================
*        filename: shared_ptr2.cpp
*        author: rambogui
*        data: 2019-01-08 17:27:24
======================================================================*/

#include <iostream>
#include <string>
#include <memory>

int main(int argc, char *argv[])
{
    std::shared_ptr<std::string> p4 = std::make_shared<std::string>("rambo");

    std::cout << *p4 << std::endl;
    std::cout << *(p4->mem) << std::endl;

    return 0;
}
