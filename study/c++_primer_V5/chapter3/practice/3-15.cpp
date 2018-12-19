/*======================================================================
*        filename: 3-15.cpp
*        author: rambogui
*        data: 2018-12-19 13:22:35
======================================================================*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::string temp;
    std::vector<std::string> svec;

    while(std::cin >> temp)
        svec.push_back(temp);

    std::cout << "svec size: " << svec.size() << std::endl;
    for (auto s : svec)
        std::cout << s << ' ';
    std::cout << std::endl;

    return 0;
}
