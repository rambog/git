/*======================================================================
*        filename: vector_pushback2.cpp
*        author: rambogui
*        data: 2018-12-19 11:26:50
======================================================================*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    std::string word;
    std::vector<std::string> text;

    while (std::cin >> word)
        text.push_back(word);

    for (auto s : text)
        std::cout << s << ' ';
    std::cout << std::endl;

    return 0;
}
