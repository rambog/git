/*======================================================================
*        filename: defconstructor.cpp
*        author: rambogui
*        data: 2018-12-13 08:18:57
======================================================================*/

#include <iostream>
#include <string>

class base
{
private:
    std::string str; 
public:
    base(const std::string& str /*= "base"*/) : str(str)
    { std::cout << "I am base constructor" << std::endl; }
};

class derive : public base
{
private:
    std::string str;
public:
    derive(const std::string& str = "derive") : str(str)
    { std::cout << "I am derive constructor" << std::endl; }
};

int main(int argc, char *argv[])
{
    derive d;
    return 0;
}
