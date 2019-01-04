/*======================================================================
*        filename: lambda_domain.cpp
*        author: rambogui
*        data: 2019-01-04 16:30:33
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    int tmp = 5;

    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9}; 

    {
        for_each(ivec.begin(), ivec.end(),
            [&tmp](int i) -> void
            { if (i >= tmp) { cout << i << ' '; ++tmp; }});
    }

    cout << endl;
    cout << tmp << endl;

    return 0;
}
