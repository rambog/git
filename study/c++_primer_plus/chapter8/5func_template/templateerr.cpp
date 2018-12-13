/*======================================================================
*        filename: templateerr.cpp
*        author: rambogui
*        data: 2018-12-01 14:01:57
======================================================================*/

#include <iostream>

template <class T>
void temp1(T, T);

void temp1(int, int);

struct foo {
    int f1;
};

int main(int argc, char *argv[])
{
    temp1(1,1);
    temp1('a', 'b');

    temp1(1, 1.0);

    foo f1, f2;


    return 0;
}

template <class T>
void temp1(T t1, T t2)
{
    using namespace std;
    if (t1 > t2)
        cout << "I am temp1" << endl;
    else 
        cout << "I am temp2" << endl;
}

void temp1(int n1, int n2)
{
    using namespace std;
    cout << "I am not temp" << endl;
}
