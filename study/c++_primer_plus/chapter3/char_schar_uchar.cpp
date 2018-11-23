/*======================================================================
*        filename: char_schar_uchar.cpp
*        author: rambogui
*        data: 2018-11-23 13:31:20
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    char och = 0xff;
    unsigned char uch = 0xff;
    signed char sch = 0xff;

    if (uch > 0)
        std::cout << "unsigned char\n";

    if (sch > 0) 
        std::cout << "signed char\n";

    if (och > 0)
        std::cout << "char is unsigned char\n";

    if (och < 0)
        std::cout << "char is signed char\n";

    uch = -1;
    return 0;
}
