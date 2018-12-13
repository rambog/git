/*======================================================================
*        filename: classfoo.h
*        author: rambogui
*        data: 2018-12-06 08:22:06
======================================================================*/

#ifndef CLASSFOO_H_
#define CLASSFOO_H_

#include <string>

class foo
{
    std::string name;
public:
    foo();
    foo(const std::string &);
    ~foo();
};

#endif
