/*======================================================================
*        filename: delete2.cpp
*        author: rambogui
*        data: 2018-11-26 10:46:46
======================================================================*/

#include <iostream>

class T {
public:
    T() {}
    ~T() { std::cout << "destructor" << std::endl; }
};

int main(int argc, char *argv[])
{
    using namespace std;
    int *ptmp;

    T *Ttmp;
    Ttmp = new T [3];
    delete Ttmp;

    while (1) {
        ptmp = new int[10*1024*1024];
        if (ptmp == NULL) cout << "new failed!\n" << endl;
        delete  ptmp;
    }

    return 0;
}
