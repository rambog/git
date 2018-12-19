/*======================================================================
*        filename: iterator_str.cpp
*        author: rambogui
*        data: 2018-12-19 14:53:35
======================================================================*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<std::string> svec;
    std::string str;

    while (std::cin >> str)
        svec.push_back(str);
    svec.push_back(std::string());
    std::cout << svec.size() << ' ' << svec.cbegin() - svec.cend() << std::endl;

    int i = 0;
    std::vector<std::string>::const_iterator citer;
    for (citer = svec.cbegin(); citer != svec.cend() && !citer->empty(); ++citer) {
        std::cout << *citer << std::endl;
        i++;
    }
    std::cout << i << std::endl;

    return 0;
}
