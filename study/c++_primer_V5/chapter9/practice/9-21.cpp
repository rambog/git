/*======================================================================
*        filename: 9-21.cpp
*        author: rambogui
*        data: 2018-12-27 08:20:39
======================================================================*/

#include <iostream>
#include <vector>
#include <forward_list>

using std::vector;
using std::string;
using std::endl;
using std::cin;
using std::cout;

int main(int argc, char *argv[])
{
    vector<string> svec;
    string word;
    vector<string>::iterator citer = svec.begin();

    while (cin >> word)
        citer = svec.insert(citer, word);

    while (citer != svec.end())
        cout << *citer++ << ' ';
    cout << endl;

    return 0;
}
