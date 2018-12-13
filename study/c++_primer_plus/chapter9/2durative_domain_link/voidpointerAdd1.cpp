/*======================================================================
*        filename: voidpointerAdd1.cpp
*        author: rambogui
*        data: 2018-12-03 17:28:27
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int *ptmp = new int[10];

    void *pvid = (void*)ptmp;

    std::cout << pvid << ' ' << ptmp << std::endl;
    std::cout << pvid+1 << ' ' << ptmp+1 << std::endl;

    return 0;
}
