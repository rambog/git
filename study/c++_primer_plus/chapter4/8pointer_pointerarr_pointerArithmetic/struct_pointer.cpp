/*======================================================================
*        filename: struct_pointer.cpp
*        author: rambogui
*        data: 2018-11-26 14:13:23
======================================================================*/

#include <iostream>

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(int argc, char *argv[])
{
    inflatable *pinflat;
    inflatable foo = {"ramb", 0.1, 0.2};
    pinflat = &foo;

    std::cout << (*pinflat).name << std::endl; 
    std::cout << *pinflat->name << std::endl;

    std::cout << (*pinflat).volume << std::endl;
    return 0;
}
