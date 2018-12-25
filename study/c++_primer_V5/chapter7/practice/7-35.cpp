/*======================================================================
*        filename: 7-35.cpp
*        author: rambogui
*        data: 2018-12-25 09:26:30
======================================================================*/

#include <iostream>
#include <string>

typedef std::string Type;
Type initVal();

class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal() { return 0.0; }
private:
    int val;
};

Exercise::Type Exercise::setVal(Type para) {
    val = para + initVal();
    return val;
}

int main(int argc, char *argv[])
{

    return 0;
}
