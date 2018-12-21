/*======================================================================
*        filename: process.cpp
*        author: rambogui
*        data: 2018-12-21 14:46:27
======================================================================*/

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

const vector<string> &process()
{
    return {"rambo", "guiyao"};
}

int main(int argc, char *argv[])
{
    std::cout << &(process()) << std::endl;    
    vector<string> &ref = const_cast<vector<string> &>(process());
    std::cout << &ref << std::endl;
    ref[0] = "hello";
    return 0;
}
