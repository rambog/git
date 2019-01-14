/*======================================================================
*        filename: new_shared_ptr.cpp
*        author: rambogui
*        data: 2019-01-14 15:27:19
======================================================================*/

#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    int *ip;
    {
        ip = new int[50] {1,2,3,4,5}; 
        std::shared_ptr<int> p(ip);

        for (int i = 0; i < 50; ++i)
            std::cout << ip[i] << ' ';
        std::cout << std::endl;

        std::cout << ip << ' ' << p.get() << std::endl;
    }

    for (int i = 0; i < 50; ++i) {
        ip[i] = i;
        std::cout << ip[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
