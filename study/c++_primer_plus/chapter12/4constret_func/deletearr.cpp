/*======================================================================
*        filename: deletearr.cpp
*        author: rambogui
*        data: 2018-12-10 10:46:28
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    char* p;

#if 0
    while (1) {
        p = new char[10*1024*1024];
        char (*tmp)[] = (char (*)[])p;
        delete p;
    }
#else
    while (1) {
        p = new char[10*1024*1024];
        //delete p;
    }
#endif

    return 0;
}
