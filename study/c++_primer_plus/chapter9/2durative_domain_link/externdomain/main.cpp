/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-03 10:45:28
======================================================================*/

#include <iostream>
#include "file1.h"
extern int externg;
int main(int argc, char *argv[])
{
    using namespace std;
    externg += 10;
    cout << "main file " << externg << endl;
    foo();
    return 0;
}
