/*======================================================================
*        filename: 6-53.cpp
*        author: rambogui
*        data: 2018-12-22 10:15:32
======================================================================*/

#include <iostream>

#if 0
int calc(int &i1, int &i2)
{
    std::cout << "first func\n";
}

int calc(const int &i1, const int &i2)
{
    std::cout << "second func\n";
}
#endif

#if 0
int calc(char *i1, char *i2)
{
    std::cout << "first func\n";
}

int calc(const char *i1, const char *i2)
{
    std::cout << "second func\n";
}
#endif

int calc(char *i1, char *i2)
{
    std::cout << "first func\n";
}

int calc(char* const i1, char* const i2)
{
    std::cout << "second func\n";
}

int main(int argc, char *argv[])
{
    char i1, i2;
    const char ci1=i1, ci2 = i2;

    calc(&i1, &i2);
    calc(&ci1, &ci2);

    return 0;
}
