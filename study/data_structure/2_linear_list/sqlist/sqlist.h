/*======================================================================
*        filename: sqlist.h
*        author: rambogui
*        data: 2019-01-15 09:41:58
======================================================================*/

#include "elem.h"
#include <initializer_list>
#include <iostream>

bool compare(const ElemType &rhs, const ElemType &lhs);
void visit(const ElemType &e);

class sqlist {
public:
    constexpr static unsigned LIST_INIT_SIZE = 10;
    constexpr static unsigned LISTINCREMENT = 2;
    typedef int qsize;

    sqlist() : pelem(new ElemType[LIST_INIT_SIZE]), len(0),
        listsize(LIST_INIT_SIZE) { }
    sqlist(std::initializer_list<ElemType> il);
    sqlist(const sqlist &sq);
    ~sqlist();

    void clear() { len = 0; }
    bool empty() const { return len == 0; }
    qsize length() const { return len; }
    void get_elem(qsize i, ElemType &e);
    qsize locate_elem(const ElemType &e, bool (*cmp)
        (const ElemType &rhs, const ElemType &lhs) = compare) const;
    void prior_elem(const ElemType &cur_e, ElemType &pre_e) const;
    void next_elem(const ElemType &cur_e, ElemType &next_e) const;
    void insert(qsize i, const ElemType &e);
    void del(qsize i, ElemType &e);
    void traverse(void (*v)(const ElemType &e) = visit) const;
    sqlist& operator=(const sqlist &sq);

friend std::ostream& operator<<(std::ostream &os, const sqlist &sq);

private:
    ElemType *pelem;
    qsize len;
    qsize listsize;
    void incre_mem();
    void check(qsize i, const char *s);
};

std::ostream& operator<<(std::ostream &os, const sqlist &sq);
