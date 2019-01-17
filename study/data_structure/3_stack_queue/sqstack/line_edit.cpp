/*======================================================================
*        filename: line_edit.cpp
*        author: rambogui
*        data: 2019-01-17 16:32:32
======================================================================*/

#include <iostream>
#include "sqstack.h"

void lineEdit(stack<char> &s, const char *str)
{
    char tmp; 
    s.reset();
    while (*str != 0x00) {
        if (*str == '#')
            s.pop(tmp);
        else if (*str == '@')
            s.reset();
        else
            s.push(*str);
        ++str;
    }
}

void printstackline(stack<char> s)
{
    int len = s.length() + 1;
    char *p = new char[len]; 
    p[len-1] = 0x00;

    char tmp;
    for (int i = len-2; i >=0; --i) {
        s.pop(tmp);
        p[i] = tmp;
    }
    std::cout << p << std::endl;
    delete [] p;
}

int main(int argc, char *argv[])
{
    stack<char> s;

    lineEdit(s, "whli##ilr#e(s#*s)");
    printstackline(s);
    lineEdit(s, "outcha@putchar(*s=#++)");
    printstackline(s);

    return 0;
}
