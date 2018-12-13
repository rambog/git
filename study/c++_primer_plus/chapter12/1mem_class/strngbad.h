/*======================================================================
*        filename: strngbad.h
*        author: rambogui
*        data: 2018-12-08 16:56:42
======================================================================*/

#ifndef STRNGBAD_H_
#define STRNGBAD_H_

#include <iostream>

class StringBad
{
private:
    char *str;
    int len;
    static int num_strings;
public:
    StringBad(const char *s);
    StringBad();
    StringBad(const StringBad &);
    ~StringBad();
    
    friend std::ostream& operator<< (std::ostream &os, const StringBad &st);
    void operator= (const StringBad &);
};

#endif
