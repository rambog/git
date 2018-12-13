/*======================================================================
*        filename: inlines.cpp
*        author: rambogui
*        data: 2018-11-30 09:44:47
======================================================================*/

#include <iostream>

inline void func(int);

int main(int argc, char *argv[])
{
    while (1) {
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
        func(1);
    }
    return 0;
}

inline void func(int tmp)
{
   tmp * tmp;
}
