/*======================================================================
*        filename: 13-18.cpp
*        author: rambogui
*        data: 2019-01-07 10:54:10
======================================================================*/

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

class Employee {
private:
    static long idorder;
    string name; 
    long id;
public:
    Employee(const string &s = string()) :
        name(s) { id = idorder++; }
};

long Employee::idorder = 0;

int main(int argc, char *argv[])
{

    return 0;
}
