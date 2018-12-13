/*======================================================================
*        filename: pointerpara_overload.cpp
*        author: rambogui
*        data: 2018-12-01 10:55:30
======================================================================*/

#include <iostream>

void foo(int);
void foo(const long int);

void foop(char *);
void foop(const char *);

int main(int argc, char *argv[])
{
    const char *p1 = "I am rambo\n";
    char str[] = "I am guiyao\n";

    foop(p1);
    foop(str);

    return 0;
}

void foo(int n)
{

}

void foo(const long int n)
{

}

void foop(char *)
{
    using namespace std;
    cout << "I am not const" << endl;
}

void foop(const char *)
{
    using namespace std;
    cout << "I am const" << endl;
}
