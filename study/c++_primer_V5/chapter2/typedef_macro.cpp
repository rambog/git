/*======================================================================
*        filename: typedef_macro.cpp
*        author: rambogui
*        data: 2018-12-18 17:20:05
======================================================================*/

#include <iostream>

typedef char *pchart;
#define pcharm char*

int main(int argc, char *argv[])
{
    char ch = 'a';
    char ch1 = 'b';
    const pchart pt = &ch;
    const pcharm pm = &ch;

#if 0
    (*pm)++;    
    pt = &ch1;
#endif

    pm = &ch1;
    (*pt)++;

    return 0;
}
