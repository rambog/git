/*======================================================================
*        filename: shared_ptr.cpp
*        author: rambogui
*        data: 2019-01-08 17:21:08
======================================================================*/

#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    std::shared_ptr<int> vp = std::make_shared<int>();
    std::cout << vp.use_count() << std::endl;
    std::shared_ptr<int> ip(vp);
    std::cout << vp.use_count() << ' ' << ip.use_count() << std::endl;
    return 0;
}
