/*======================================================================
*        filename: vitural_destructor.cpp
*        author: rambogui
*        data: 2018-12-11 15:47:46
======================================================================*/

#include <iostream>

class foo
{
public:
    ~foo() { std::cout << "I am foo class destructor\n"; }
};

class baseclass
{
public:
    ~baseclass() { std::cout << "I am baseclass destructor\n"; }
};

class deriveclass : public baseclass
{
private:
    foo f;
public:
    virtual ~deriveclass() { std::cout << "I am deriveclass destructor\n"; }
    void done() {}
};

int main(int argc, char *argv[])
{
    baseclass* pbs[4];

    pbs[0] = new baseclass;
    pbs[1] = new deriveclass;
    pbs[2] = new baseclass;
    pbs[3] = new deriveclass;

    deriveclass d;
    //d.done();

    for (int i = 0; i < 4; i++) {
        delete pbs[i];
        std::cout << std::endl;
    }

    return 0;
}
