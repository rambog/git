/*======================================================================
*        filename: 3-40.cpp
*        author: rambogui
*        data: 2018-12-19 18:55:18
======================================================================*/

#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    char str1[] = "I am rambo, ";
    char str2[] = "I am very happy.";

    char str[sizeof(str1)+sizeof(str2)-1];

    std::strcpy(str, str1);
    std::strcat(str, str2);

    std::cout << str1 << str2 << std::endl;
    std::cout << str << std::endl;
    std::cout << sizeof str1 << ' ' << sizeof str2 << std::endl;
    std::cout << sizeof str << std::endl;

    return 0;
}
