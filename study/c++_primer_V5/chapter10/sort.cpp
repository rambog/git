/*======================================================================
*        filename: sort.cpp
*        author: rambogui
*        data: 2018-12-29 11:12:32
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, char *argv[])
{
    std::string tmp; 
    std::vector<std::string> sv;

    while (std::cin >> tmp)
        sv.push_back(tmp);

    sort(sv.begin(), sv.end());
    std::vector<std::string>::iterator iter = unique(sv.begin(), sv.end());

    for (std::string tmp : sv)
        std::cout << tmp << ' ';
    std::cout << std::endl;

    sv.erase(iter, sv.end());

    for (std::string tmp : sv)
        std::cout << tmp << ' ';
    std::cout << std::endl;
    return 0;
}
