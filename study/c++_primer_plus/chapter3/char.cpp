/*======================================================================
*        filename: char.cpp
*        author: rambogui
*        data: 2018-11-23 09:47:14
======================================================================*/

#include <iostream>
#include <climits>

int main(int argc, char *argv[])
{
    char och;
    signed char sch;
    unsigned char uch;

    och = 0x00;
    sch = 0x00;
    uch = 0x00;
    std::cout << "sizeof(char):" << sizeof(char) << std::endl;

    std::cout << (int)uch << std::endl;

    och = 0xFF;
    sch = 0xFF;
    uch = 0xFF;

    std::cout << (int)uch << std::endl;

    std::cout << CHAR_MAX << " " << CHAR_MIN << " " << UCHAR_MAX << std::endl;
    std::cout << SCHAR_MAX << " " << SCHAR_MIN << std::endl;

    och = 'A', sch = 'B', uch = 'C';
    std::cout << och << sch << uch << std::endl;

    return 0;
}
