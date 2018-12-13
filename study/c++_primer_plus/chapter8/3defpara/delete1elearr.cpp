/*======================================================================
*        filename: delete1elearr.cpp
*        author: rambogui
*        data: 2018-12-01 09:58:06
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int *p;
    while (1) {
        p = new int[10*1024*1024];
        if (p == nullptr) std::cout << "new faild!" << std::endl;
        delete p;
    }

    return 0;
}
