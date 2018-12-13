/*======================================================================
*        filename: string_literal.cpp
*        author: rambogui
*        data: 2018-11-24 10:53:26
======================================================================*/

#include <iostream>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    using namespace std;
    char pstr[] = "I am rambo";
    char *p = "I am rambo";

    cout << strlen(pstr) << " " << sizeof(pstr) << endl; 
    cout << &pstr << endl;
    cout << &p << endl;

    printf("%p\n", p);

    return 0;
}
