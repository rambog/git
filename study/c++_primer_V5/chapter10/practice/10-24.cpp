/*======================================================================
*        filename: 10-24.cpp
*        author: rambogui
*        data: 2019-01-03 14:23:22
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;

using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return sz >= s.size();
}

int main(int argc, char *argv[])
{
    vector<int> iv = {1,2,3,4,5,6,7,8,9};
    string tmp;
    if (!(cin>>tmp))
        return 1;

    std::cout << "first is: " << 
            *find_if(iv.begin(), iv.end(),
                    bind(check_size, ref(tmp), _1)) << std::endl;

    return 0;
}
