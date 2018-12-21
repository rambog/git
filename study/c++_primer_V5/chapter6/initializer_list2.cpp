/*======================================================================
*        filename: initializer_list2.cpp
*        author: rambogui
*        data: 2018-12-21 14:16:36
======================================================================*/

#include <iostream>
#include <string>
#include <vector>

void err_msg(std::vector<std::string> vl)
{
    for (std::vector<std::string>::const_iterator citer = vl.begin();
            citer != vl.end(); ++citer)
        std::cout << *citer << ' ';
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    err_msg({"rambo", "hello"});
    return 0;
}
