/*======================================================================
*        filename: 13-14.cpp
*        author: rambogui
*        data: 2019-01-07 10:17:22
======================================================================*/

#include <iostream>
#include <string>

class numbered {
public:
    int mysn = 0;
    numbered() { mysn = order++; }
    numbered(const numbered &n) 
    { mysn = order++; }

private:
    static long order;
};

void f(const numbered &s)
{
    std::cout << s.mysn << std::endl;
}

long numbered::order = 1;

int main(int argc, char *argv[])
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);

    numbered d;
    f(d);
    return 0;
}
