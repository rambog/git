/*======================================================================
*        filename: elem.cpp
*        author: rambogui
*        data: 2019-01-15 09:36:22
======================================================================*/

#include "elem.h"

std::ostream& operator<<(std::ostream &os, const ElemType &E)
{
    os << E.elem;
    return os;
}

bool ElemType::operator==(const ElemType &e) const
{
    return elem == e.elem;
}

bool ElemType::operator<(const ElemType &e) const
{
    return elem < e.elem;
}
