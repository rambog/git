/*======================================================================
*        filename: 5-4.cpp
*        author: rambogui
*        data: 2018-12-20 17:05:39
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string str("rambo");
    
    //while ((std::string::iterator iter = str.begin()))
    //while ((std::string::iterator iter = str.begin()) != str.end())
    //while (int i = 0)
    while (std::string::iterator iter != str.end())
        ;
    //std::string::iterator iter = str.begin();
    //while (iter != str.end());

    return 0;
}
