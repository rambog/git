/*======================================================================
*        filename: 3-17.cpp
*        author: rambogui
*        data: 2018-12-19 13:44:12
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main(int argc, char *argv[])
{
    std::vector<std::string> vec;
    std::string temp;

    while (std::cin >> temp)
        vec.push_back(temp);
    
    for (auto &s : vec)
        for (auto &c : s)
            c = toupper(c);

    for (auto str : vec)
        std::cout << str << std::endl;

    return 0;
}
