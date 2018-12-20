/*======================================================================
*        filename: 4-20.cpp
*        author: rambogui
*        data: 2018-12-20 13:38:10
======================================================================*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    std::vector<std::string> svec = {"rambo", "guiyao", "Iam OK", "NULL"};
    std::vector<std::string>::iterator iter = svec.begin();

    //std::cout << *iter++ << ' ' << *iter << std::endl;
    std::cout << *++iter << ' ' << *iter << std::endl;
    std::cout << *iter << std::endl;

    return 0;
}
