/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-24 08:55:43
======================================================================*/

#include <iostream>
#include "person.h"

int main(int argc, char *argv[])
{
    Person p(std::cin);
    person_print(std::cout, p) << std::endl;

    return 0;
}
