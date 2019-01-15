/*======================================================================
*        filename: linklist.cpp
*        author: rambogui
*        data: 2019-01-15 14:17:27
======================================================================*/

#include <iostream>
#include <stdexcept>
#include <string>
#include "linklist.h"

bool compare(const ElemType &lhs, const ElemType &rhs)
{
    return lhs == rhs;
}

void visit(const ElemType &e)
{
    std::cout << e << ' ';
}

void linklist::reset()
{
    linknode *tmp;
    while (plink != nullptr) {
        tmp = plink;
        plink = plink->next;
        delete tmp;
    }
    len = 0;
    plink = tail = nullptr;
}

void linklist::check(lsize i, const char *s)
{
    if (i < 0 || i >= len)
        throw std::out_of_range(std::string(s));
}

linklist::linklist() : plink(nullptr), tail(nullptr), len(0) { }

linklist::linklist(std::initializer_list<ElemType> il) : plink(nullptr), tail(nullptr), len(0)
{
    linknode **tmp = &plink;
    for (std::initializer_list<ElemType>::iterator beg = il.begin();
        beg != il.end(); ++beg) {
        if (*tmp == nullptr) {
            *tmp = new linknode(*beg);
            tmp = &((*tmp)->next);
        }
        ++len;
        tail = *tmp;
    }
}

linklist::linklist(const linklist &ll)
{
    linknode **tmp = &plink;
    linknode *tmpr = ll.plink;
    while (tmpr != nullptr) {
        *tmp = new linknode(tmpr->data);
        tmp = &((*tmp)->next);
        tmpr = tmpr->next;
        tail = *tmp;
    }
    len = ll.len;
}

linklist::~linklist()
{
    reset();
}

void linklist::clear()
{
    reset();
}

void linklist::get_elem(lsize i, ElemType &e)
{
    check(i, "get elem out of range");

    linknode *tmp = plink;
    for (int idx = 0; idx < i; ++i)
        tmp = plink->next;

    e = tmp->data;
}

linklist::lsize
linklist::locate_elem(const ElemType &e,
    bool (*cmp)(const ElemType &lhs, const ElemType &rhs))
{
    lsize idx = -1;
    linknode *tmp = plink;

    while (tmp != nullptr) {
        ++idx;
        if (cmp(e, tmp->data)) 
            return idx;
        tmp = tmp->next;
    }

    return -1;
}

bool linklist::prior_elem(const ElemType &cur_e, ElemType &pre_e)
{
    linknode *tmp = plink;

    while (tmp->next != nullptr) {
        if ((tmp->next)->data == cur_e) {
            pre_e = tmp->data;
            return true;
        }
    }
    return false;
}

bool linklist::next_elem(const ElemType &cur_e, ElemType &next_e)
{
    linknode *tmp = plink;

    while (tmp->next != nullptr) {
        if (tmp->data == cur_e) {
            next_e = (tmp->next)->data; 
            return true;
        }
    }
    return false;
}

void linklist::insert(lsize i, const ElemType &e)
{
    if (i < 0 || i > len)
        throw std::out_of_range(std::string("insert out of range"));

    linknode *pre= nullptr;
    for (int idx = 0; idx < i; ++idx) {
        if (pre == nullptr)
            pre = plink;
        else
            pre = pre->next;
    }
    linknode *tmp = new linknode(e);
    if (pre == nullptr) {
        if (plink == nullptr)
            tail = tmp;
        tmp->next = plink;
        plink = tmp;
    } else {
        tmp->next = pre->next;
        pre->next = tmp;
        if (tmp->next == nullptr)
            tail = tmp;
    }
    ++len;
}

void linklist::del(lsize i, ElemType &e)
{
    check(i, "del out of range");

    linknode *pre = nullptr;
    for (int idx = 0; idx < i; ++idx) {
        if (pre == nullptr)
            pre = plink;
        else
            pre = pre->next;
    }
    linknode *tmp;
    if (pre == nullptr) {
        tmp = plink;
        plink = plink->next;
        if (plink == nullptr)
            tail = plink;
    } else {
        tmp = pre->next;
        pre->next = pre->next->next;
        if (tmp->next == nullptr) 
            tail = pre;
    }
    e = tmp->data;
    delete tmp;
    --len;
}

void linklist::traverse(void (*v)(const ElemType &e)) const
{
    linknode *tmp = plink;
    while (tmp != nullptr) {
        v(tmp->data);
        tmp = tmp->next;
    }
}

linklist&
linklist::operator=(const linklist &rhs)
{
    if (this != &rhs) {
        linknode *tmpr = rhs.plink;
        linknode **tmpl = &plink;
        while (tmpr != nullptr) {
            if (*tmpl == nullptr) {
                *tmpl = new linknode(tmpr->data);
            } else {
                (*tmpl)->data = tmpr->data;
            }
            tmpl = &((*tmpl)->next);
            tmpr = tmpr->next;
        }
    }
}

const linklist::linknode* linklist::get_mem() const
{
    return plink;
}

void linklist::push_back(const ElemType &e)
{
    if (tail == nullptr) {
        plink = new linknode(e);
        tail = plink;
    }
    else {
        tail->next = new linknode(e);
        tail = tail->next;
    }
}

std::ostream& operator<<(std::ostream &os, const linklist &ll) 
{
    const linklist::linknode *tmp = ll.plink;

    while (tmp != nullptr) {
        std::cout << tmp->data << ' ';
        tmp = tmp->next;
    }

    return os;
}
