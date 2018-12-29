/*======================================================================
*        filename: accumulate_string.cpp
*        author: rambogui
*        data: 2018-12-29 08:44:33
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    vector<string> sv = {"rambo ", "gui ", "yao ", "ram"};
    //std::cout << accumulate(sv.begin(), sv.end(), string("")) << std::endl;
    std::cout << accumulate(sv.begin(), sv.end(), "") << std::endl;
    return 0;
}
