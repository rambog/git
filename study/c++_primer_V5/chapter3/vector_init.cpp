/*======================================================================
*        filename: vector_init.cpp
*        author: rambogui
*        data: 2018-12-19 10:53:42
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    using namespace std;
    
    vector<int> ivec = (vector<int>)10;
    vector<int> ivec2 = ivec;

    cout << ivec.size() << endl;
    cout << ivec2.size() << endl;

    return 0;
}
