/*======================================================================
*        filename: person.cpp
*        author: rambogui
*        data: 2018-12-22 16:06:41
======================================================================*/

#include <iostream>
#include "person.h"

Person::Person(std::istream &is)
{
    person_read(is, *this);
}

std::istream &person_read(std::istream &is, Person &item)
{
    is >> item.name >> item.address;
    return is;
}

std::ostream &person_print(std::ostream &os, const Person &item)
{
    os << "name:" << item.name << ' '
       << "address:" << item.address;
    return os;
}
