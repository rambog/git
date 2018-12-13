/*======================================================================
*        filename: pointer_and_array_noborder.cpp
*        author: rambogui
*        data: 2018-12-12 18:27:38
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    char table[][] = {
        "rambo",
        "guiyao",
        "rambogui"
    };

    char (*ptmp)[] = table;

    return 0;
}
