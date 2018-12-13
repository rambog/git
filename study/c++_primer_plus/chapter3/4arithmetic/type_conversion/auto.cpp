/*======================================================================
*        filename: auto.cpp
*        author: rambogui
*        data: 2018-11-24 08:53:03
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    auto a1 = 0;
    auto a2 = 65536;
    auto a3 = 0.0;
    auto a4 = 0.0F;
    auto a5 = 0L;
    auto a6 = 0LL;
    auto a7 = true;
    auto a8 = 0.0L;
    
    cout << sizeof a1 << endl;
    cout << sizeof a2 << endl;
    cout << sizeof a3 << endl;
    cout << sizeof a4 << endl;
    cout << sizeof a5 << endl;
    cout << sizeof a6 << endl;
    cout << sizeof a7 << endl;
    cout << sizeof a8 << endl;

    return 0;
}
