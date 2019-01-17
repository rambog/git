/*======================================================================
*        filename: sqtack.cpp
*        author: rambogui
*        data: 2019-01-17 13:47:00
======================================================================*/

#include "sqstack.h"

std::ostream& operator<<(std::ostream &os, const elem_type &e)
{
    os << e.elem;
    return os;
}
