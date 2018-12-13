/*======================================================================
*        filename: structunion.cpp
*        author: rambogui
*        data: 2018-11-24 17:21:47
======================================================================*/

#include <iostream>

union id
{
    long id_num;
    char id_char[20];
};

union fid
{
    int id_num;
    char id_char[20];
};

struct foo1
{
    char brand[20];
    int type;
    union id
    {
        int id_num;
        char id_char[20];
    } id_val;
};

struct foo2
{
    char brand[20];
    int type;
    union 
    {
        long id_num;
        char id_char[20];
    };
};

struct tmp
{
    short tmpf;
    char tmpfoo;
    int tmpfoo1;
};

int main(int argc, char *argv[])
{
    using namespace std;

    cout << sizeof(id) <<endl;
    cout << sizeof(fid) <<endl;
    cout << sizeof(foo1) << endl;
    cout << sizeof(foo2) << endl;
    cout << sizeof(tmp) << endl;

    return 0;
}
