/*======================================================================
*        filename: 9-43.cpp
*        author: rambogui
*        data: 2018-12-27 15:26:48
======================================================================*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void replace(string &s, const string &oldVal, const string &newVal)
{
    string::iterator siter = s.begin();
    while (siter-s.end() >= oldVal.size()) {
        string::const_iterator tmp = oldVal.begin();    
        while (tmp != oldVal.end())
            if (*siter++ != *tmp++)
                break;
        if (tmp == oldVal.end()) {
            siter = s.erase(siter, stmp);
            //siter = s.insert(siter, newVal.begin(), newVal.end());
            s.insert(siter, newVal.begin(), newVal.end());
            siter = s.begin();
        } 
        siter++;
    }
}

int main(int argc, char *argv[])
{
    string tmp;
    getline(cin, tmp);
    string oldval = "ram";
    string newval = "rambo";

    replace(tmp, oldval, newval);
    cout << tmp << endl;

    return 0;
}
