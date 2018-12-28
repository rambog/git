/*======================================================================
*        filename: 9-44.cpp
*        author: rambogui
*        data: 2018-12-27 16:37:18
======================================================================*/

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

void replace(string &s, const string &oldVal, const string &newVal)
{
    string::iterator siter = s.begin();
    while (siter - s.end() >= oldVal.size()) {
        string::const_iterator olditer = oldVal.begin();
        string::iterator tmpiter = siter;
        while (olditer != oldVal.end())
            if (*olditer++ != *tmpiter++)
                break;

        if (olditer == oldVal.end()) {
            s.replace(siter, siter+oldVal.size(), newVal.c_str());
            siter = s.begin();
        } else
            ++siter;
    }
}

int main(int argc, char *argv[])
{
    string line;
    getline(cin, line);
    string oldVal("rambo");
    string newVal("guiyao");
    replace(line, oldVal, newVal);
    cout << line << endl;
    return 0;
}
