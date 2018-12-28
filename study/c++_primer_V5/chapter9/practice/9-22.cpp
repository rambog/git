/*======================================================================
*        filename: 9-22.cpp
*        author: rambogui
*        data: 2018-12-27 08:33:23
======================================================================*/

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    int someval;
    vector<int> ivec;

    while (cin >> someval)
        ivec.push_back(someval);
    cin.clear();
    cin >> someval;
    cout << "someval: " << someval << endl;
    
    vector<int>::iterator iter = iv.begin(),
                        mid = iv.begin() + iv.size()/2;

    while (iter != mid)
        if (*iter == someval)

    return 0;
}
