/*======================================================================
*        filename: alarm_char.cpp
*        author: rambogui
*        data: 2018-11-23 11:25:37
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    char alarm = '\a';
    std::cout << alarm << "Don't do that again!\a\n";
    std::cout << '\?' << std::endl;
    return 0;
}
