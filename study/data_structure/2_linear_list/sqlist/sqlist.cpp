/*======================================================================
*        filename: sqlist.cpp
*        author: rambogui
*        data: 2019-01-15 09:41:58
======================================================================*/

#include <stdexcept>
#include <string>

#include "sqlist.h"

bool compare(const ElemType &rhs, const ElemType &lhs)
{
    return rhs == lhs;
}

void visit(const ElemType &e)
{
    std::cout << e << ' ';
}

void sqlist::incre_mem()
{
    ElemType *tmp = new ElemType[listsize + LISTINCREMENT];
    for (int i = 0; i < listsize; ++i) 
        tmp[i] = pelem[i];
    delete[] pelem;
    pelem = tmp;
    listsize += LISTINCREMENT;
}

void sqlist::check(qsize i, const char *s)
{
    if (i >= len) 
        throw std::out_of_range(std::string(s));
}

sqlist::sqlist(std::initializer_list<ElemType> il) : 
    pelem(new ElemType[(il.size() > LIST_INIT_SIZE) ? il.size() :
        LIST_INIT_SIZE]), len(il.size()), listsize(
        (il.size() > LIST_INIT_SIZE) ? il.size() : LIST_INIT_SIZE)
{
    int idx = 0;
    for (std::initializer_list<ElemType>::iterator beg = il.begin();
        beg != il.end(); ++beg) 
        pelem[idx++] = *beg;
}

sqlist::sqlist(const sqlist &sq)
{
    len = sq.len;
    listsize = sq.listsize;
    pelem = new ElemType[sq.listsize];
    for (int i = 0; i < len; ++i)
        pelem[i] = sq.pelem[i];
}

sqlist::~sqlist() 
{
    delete[] pelem;
}

void sqlist::get_elem(qsize i, ElemType &e) 
{
    check(i, "get elem out of range");
    e = pelem[i];
}

sqlist::qsize sqlist::locate_elem(const ElemType &e, bool (*cmp)
    (const ElemType &rhs, const ElemType &lhs)) const
{
    for (int i = 0; i < len; ++i)
        if (cmp(pelem[i], e))
            return i;
    return -1;
}

void sqlist::prior_elem(const ElemType &cur_e, ElemType &pre_e) const
{
    for (int i = 1; i < len; ++i)
        if (pelem[i] == cur_e) {
            pre_e = pelem[i-1];
            return;
        }
}

void sqlist::next_elem(const ElemType &cur_e, ElemType &next_e) const
{
    for (int i = 0; i < len-1; ++i)
        if (pelem[i] == cur_e) {
            next_e = pelem[i+1];
            return;
        }
}

void sqlist::insert(qsize i, const ElemType &e)
{
    if (i < 0 || i > len)
        throw std::out_of_range(std::string("insert out of range"));

    if (len == listsize)
        incre_mem();

    int idx;
    for (idx = len; idx != i; --idx)
        pelem[idx] = pelem[idx-1];
    pelem[idx] = e; 
    ++len;
}

void sqlist::del(qsize i, ElemType &e)
{
    check(i, "del out of range");
    e = pelem[i];

    for (int idx = i; idx < len-1; idx++) 
        pelem[idx] = pelem[idx+1];
    --len;
}

void sqlist::traverse(void (*v)(const ElemType &e)) const
{
    for (int i = 0; i < len; i++)
        v(pelem[i]);
}

sqlist& sqlist::operator=(const sqlist &sq)
{
    if (this != &sq) {
        delete[] pelem;
        pelem = new ElemType[sq.listsize];
        len = sq.len;
        listsize = sq.listsize;
        for (int i = 0; i < len; ++i)
            pelem[i] = sq.pelem[i];
    }
}

std::ostream& operator<<(std::ostream &os, const sqlist &sq)
{
    for (int i = 0; i < sq.len; ++i)
        os << sq.pelem[i] << ' ';
    return os;
}
