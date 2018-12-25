/*======================================================================
*        filename: classtypetypeuse.cpp
*        author: rambogui
*        data: 2018-12-25 09:13:07
======================================================================*/

#include <iostream>

typedef double Money;
class Account {
public:
    Money money;
    //double money;
private:
    typedef double Money;
    Money bal;
};

int main(int argc, char *argv[])
{

    return 0;
}
