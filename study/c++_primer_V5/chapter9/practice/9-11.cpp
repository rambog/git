/*======================================================================
*        filename: 9-11.cpp
*        author: rambogui
*        data: 2018-12-26 09:27:45
======================================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <array>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::array;

void printvec(const vector<string> &vec)
{
    vector<string>::const_iterator beg = vec.begin(),
                             end = vec.end();
    while (beg != end)
        std::cout << "cot: " << *beg++ << ' ';
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    vector<string> o {"rambo", "guiyao", "rambogui", "hello",
                        "world", "nice", "to meet", "you"};

    vector<string> o1(o);
    vector<string> o2 = o;
    vector<string> o3{"rambo", "guiayo", "rambogui"};
    vector<string> o4 = {"guiyao", "rambogui", "rambo"};
    vector<string> o5(10);
    vector<string> o6(10, "ram");

#if 0
    printvec(o);
    printvec(o1);
    printvec(o2);
    printvec(o3);
    printvec(o4);
    printvec(o5);
    printvec(o6);
#endif
    array<int, 3> arr = {1, 2, 3};
    array<int, 4> arr2 = arr;

    std::cout << arr2[0] << arr2[1] << arr2[2] << std::endl;

    return 0;
}
