/*======================================================================
*        filename: elem.h
*        author: rambogui
*        data: 2019-01-15 09:36:22
======================================================================*/

#include <iostream>

class ElemType {
public:
    ElemType(int e = 0) : elem(e) {}
    bool operator==(const ElemType &e) const;
    bool operator<(const ElemType &e) const;

friend std::ostream& operator<<(std::ostream &os, const ElemType &E); 

private:
    int elem;
};

std::ostream& operator<<(std::ostream &os, const ElemType &E);
