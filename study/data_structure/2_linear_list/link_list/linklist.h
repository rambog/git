/*======================================================================
*        filename: linklist.h
*        author: rambogui
*        data: 2019-01-15 14:00:57
======================================================================*/

#include <iostream>
#include <initializer_list>
#include "elem.h"

bool compare(const ElemType &lhs, const ElemType &rhs);

void visit(const ElemType &e);

class linklist {
public:
    typedef int lsize;
    struct linknode {
        ElemType data;
        linknode *next;
        linknode() = default;
        linknode(const ElemType &e) : data(e), next(nullptr) { }
    };

    linklist();
    linklist(std::initializer_list<ElemType> il);
    linklist(const linklist &ll);
    ~linklist();

    void clear();
    bool empty() const { return len == 0; }
    lsize length() const { return len; }
    void get_elem(lsize i, ElemType &e);
    lsize locate_elem(const ElemType &e,
        bool (*cmp)(const ElemType &lhs, const ElemType &rhs) = compare);
    bool prior_elem(const ElemType &cur_e, ElemType &pre_e);
    bool next_elem(const ElemType &cur_e, ElemType &next_e);
    void insert(lsize i, const ElemType &e);
    void del(lsize i, ElemType &e);
    void traverse(void (*v)(const ElemType &) = visit) const;
    linklist& operator=(const linklist &rhs);
    const linknode* get_mem() const;
    void push_back(const ElemType &e);

friend std::ostream& operator<<(std::ostream &os, const linklist &ll);

private:
    linknode *plink; 
    linknode *tail;
    lsize len;
    void reset();
    void check(lsize i, const char *s);
};

std::ostream& operator<<(std::ostream &os, const linklist &ll);
