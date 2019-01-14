/*======================================================================
*        filename: shared_ptr3.cpp
*        author: rambogui
*        data: 2019-01-12 10:05:30
======================================================================*/

#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    std::cout << (std::make_shared<int>(1)).use_count() << std::endl;
    std::shared_ptr<int> tmpptr = std::make_shared<int>(2);
    return 0;
}
