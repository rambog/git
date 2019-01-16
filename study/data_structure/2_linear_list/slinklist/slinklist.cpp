/*======================================================================
*        filename: slinklist.cpp
*        author: rambogui
*        data: 2019-01-16 08:16:19
======================================================================*/

#include "slinklist.h"
#include <stdexcept>

bool slinklist::elemtype::operator==(const elemtype &rhs) const
{
    return elem == rhs.elem;
}

void slinklist::init(slinklist_size size)
{
    int i;
    for (i = 0; i < size-1; ++i)
        pslinklist[i].cur = i + 1;
    pslinklist[i].cur = 0;
}

void slinklist::mem_incre()
{
    component *tmp = new component[llsize + INCREMENT]; 

    slinklist_size i, freetail = 0;
    for (i = 0; i < llsize; ++i)
        tmp[i] = pslinklist[i];
    delete[] pslinklist;
    pslinklist = tmp;

    while (pslinklist[freetail].cur != 0)
        freetail = pslinklist[freetail].cur;
    pslinklist[freetail].cur = llsize;

    llsize += INCREMENT;
    for ( ;i < llsize-1; ++i)
        pslinklist[i].cur = i + 1;
    pslinklist[i].cur = 0;
}

void slinklist::check(slinklist_size i, const char *s)
{
    if (i < 0 || i >= leng)
        throw std::out_of_range(std::string(s));
}

slinklist::slinklist() : pslinklist(new component[MAXSIZE]), llsize(MAXSIZE), 
    head(0), tail(0), leng(0)
{
    init(llsize); 
}

slinklist::slinklist(std::initializer_list<elemtype> il) : 
    pslinklist(new component[il.size() > MAXSIZE ? il.size() : MAXSIZE]),
    llsize(il.size() > MAXSIZE ? il.size() : MAXSIZE), head(0), tail(0), leng(0)
{
    init(llsize);
    for (std::initializer_list<elemtype>::iterator beg = il.begin();
        beg != il.end(); ++beg)
        push_back(*beg);
}

slinklist::slinklist(const slinklist &sll) : pslinklist(new component[sll.llsize]),
    llsize(sll.llsize), head(sll.head), tail(sll.head), leng(sll.leng) 
{
    for (int i = 0; i < sll.llsize; ++i)
        pslinklist[i] = (sll.pslinklist)[i];
}

slinklist::~slinklist()
{
    delete[] pslinklist;
}

slinklist& slinklist::operator=(const slinklist &sll)
{
    if (this != &sll) {
        delete[] pslinklist;
        pslinklist = new component[sll.llsize];
        llsize = sll.llsize;
        for (int i = 0; i < llsize; ++i)
            pslinklist[i] = (sll.pslinklist)[i];
        head = sll.head;
        tail = sll.tail;
        leng = sll.leng;
    }
    return *this;
}

bool slinklist::reset()
{
    init(llsize);
    head = tail = leng = 0;
}

void slinklist::insert(slinklist_size i, const elemtype &e)
{
    if (i < 0 || i > leng)
        throw std::out_of_range(std::string("insert out of range"));
    if (pslinklist[0].cur == 0)
        mem_incre();

    slinklist_size ifree = pslinklist[0].cur; 
    pslinklist[0].cur = pslinklist[ifree].cur;
    ++leng;

    slinklist_size pre = head;
    bool ishead = true;
    for ( ;i > 0; --i) {
        if (ishead)
            ishead = false;
        else 
            pre = pslinklist[pre].cur;
    }

    pslinklist[ifree].data = e;
    if (ishead) {
        pslinklist[ifree].cur = head;
        head = ifree;
    } else {
        pslinklist[ifree].cur = pslinklist[pre].cur;
        pslinklist[pre].cur = ifree;
    }
    if (pslinklist[ifree].cur == 0)
        tail = ifree;
}

void slinklist::delelem(slinklist_size i, elemtype &e)
{
    check(i, "delelem out if range");

    slinklist_size pre = head;
    slinklist_size ifree = 0;
    bool ishead = true;
    for ( ; i > 0; --i) {
        if (ishead)
            ishead = false;
        else
            pre = pslinklist[pre].cur;
    }
    
    if (ishead) {
        ifree = head;
        head = pslinklist[head].cur;
    } else {
        ifree = pslinklist[pre].cur;
        pslinklist[pre].cur = pslinklist[ifree].cur;
    }
    if (pslinklist[ifree].cur == 0)
        if (ishead)
            tail = 0;
        else 
            tail = pre;
    e = pslinklist[ifree].data;
    pslinklist[ifree].cur = pslinklist[0].cur;
    pslinklist[0].cur = ifree;
    --leng;
}

void slinklist::push_back(const elemtype &e)
{
    if (pslinklist[0].cur == 0)
        mem_incre();
    slinklist_size ifree = pslinklist[0].cur;
    pslinklist[0].cur = pslinklist[ifree].cur;
    
    pslinklist[ifree].data = e;
    pslinklist[ifree].cur = 0;

    if (head == 0) {
        head = ifree;
    } else {
        pslinklist[tail].cur = ifree;
    }
    tail = ifree;
    ++leng;
}

void slinklist::push_back(std::initializer_list<elemtype> il)
{
    for (std::initializer_list<elemtype>::iterator beg = il.begin();
        beg != il.end(); ++beg)
        push_back(*beg);
}

slinklist::slinklist_size
slinklist::locate_elem(const elemtype &e, 
    bool (*cmp)(const elemtype &lhs, const elemtype &rhs))
{
    for (slinklist_size idx = 0, cur = head; cur != 0;
        cur = pslinklist[cur].cur, ++idx)
        if (cmp(e, pslinklist[cur].data))
            return idx;
    return -1;
}

const slinklist::component* slinklist::get_mem() const
{
    return pslinklist;
}

bool compare(const slinklist::elemtype &lhs, const slinklist::elemtype &rhs)
{
    return lhs == rhs;
}

std::ostream& operator<<(std::ostream &os, const slinklist::elemtype &e)
{
    os << e.elem;
    return os;
}

std::ostream& operator<<(std::ostream &os, const slinklist::component &c)
{
    os << c.data << ' ' << c.cur;
    return os;
}

std::ostream& operator<<(std::ostream &os, const slinklist &sll)
{
    slinklist::slinklist_size cur = sll.head;
    while (cur != 0) {
        os << (sll.pslinklist)[cur].data << ' ';
        cur = (sll.pslinklist)[cur].cur;
    }
    return os;
}
