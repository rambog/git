/*======================================================================
*        filename: polynomial.cpp
*        author: rambogui
*        data: 2019-01-17 08:22:03
======================================================================*/

#include "polynomial.h"

void polynomial::reset()
{
    term *tmp = head->next;
    term *pre;
    while (tmp != nullptr) {
        pre = tmp;
        tmp = tmp->next;
        delete pre;
    }
    head->next = nullptr;
}

polynomial::polynomial(std::initializer_list<term> il) : head(new term())
{
    for (std::initializer_list<term>::iterator beg = il.begin();
        beg != il.end(); ++beg) {
        insert(*beg);
    }
}

polynomial::polynomial(const polynomial &p) : head(new term())
{
    term *tmp = head; 
    term *copyed = p.head->next;
    while (copyed != nullptr) {
        tmp->next = new term(copyed->coef, copyed->expn);
        tmp = tmp->next;
        copyed = copyed->next;
    }
}

polynomial::~polynomial()
{
    reset();
    delete head;
}

polynomial& polynomial::operator=(const polynomial &p)
{
    if (this != &p) {
        reset();
        term *tmp = head;
        term *copyed = p.head->next;
        while (copyed != nullptr) {
            tmp->next = new term(copyed->coef, copyed->expn);
            tmp = tmp->next;
            copyed = copyed->next;
        }
    }
    return *this;
}

polynomial& polynomial::operator+=(const polynomial &p)
{
    term *tmpr = p.head->next;
    term *tmpl = head->next;
    term *pre = head;
    while (tmpr != nullptr && tmpl != nullptr) {
        if (tmpr->expn < tmpl->expn) {
            pre->next = new term(tmpr->coef, tmpr->expn); 
            pre->next->next = tmpl;
            pre = pre->next;
            tmpr = tmpr->next;
        } else if (tmpr->expn > tmpl->expn) {
            pre = tmpl;
            tmpl = tmpl->next;
        } else {
            tmpl->coef += tmpr->coef;
            pre = tmpl;
            tmpl = tmpl->next;
            tmpr = tmpr->next;
        }
    }

    while (tmpr != nullptr) {
        pre->next = new term(tmpr->coef, tmpr->expn);
        pre->next->next = tmpl;
        pre = pre->next;
        tmpr = tmpr->next;
    }
    return *this;
}

polynomial& polynomial::operator*=(const term &t)
{
    if (t.coef == 0) {
        reset();
    } else {
        term *tmp = head->next;
        while (tmp != nullptr) {
            tmp->coef *= t.coef;
            tmp->expn += t.expn;
            tmp = tmp->next;
        }
    }

    return *this;
}

polynomial& polynomial::operator*=(const polynomial &p)
{
    term *tmp = p.head->next;
    polynomial tmpd(*this);
    reset();
    while (tmp != nullptr) {
        operator+=(tmpd*(*tmp));
        tmp = tmp->next;
    }
    return *this;
}

void polynomial::insert(const term &t)
{
    term *tmp = head->next;
    term *pre = head;
    while (tmp != nullptr) {
        if (tmp->expn == t.expn) {
            tmp->coef += t.coef;
            return;
        }

        if (tmp->expn > t.expn) break;
        pre = tmp;
        tmp = tmp->next;
    }

    pre->next = new term(t.coef, t.expn);
    pre->next->next = tmp;
}

std::ostream& operator<<(std::ostream& os, const polynomial::term &t)
{
    if (t.coef != 1) os << t.coef;
    if (t.expn != 0) {
        os << 'x';
        if (t.expn != 1) os << '(' << t.expn << ')';
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const polynomial &p)
{
    const polynomial::term *tmp = p.head->get_next();
    
    if (tmp != nullptr)
        os << "f(x) = ";

    while (tmp != nullptr) {
        if (tmp->get_next() != nullptr)
            os << *tmp << " + ";
        else
            os << *tmp;
        tmp = tmp->get_next();
    }

    return os;
}

polynomial operator+(const polynomial &lhs, const polynomial &rhs)
{
    polynomial tmp = lhs;
    return tmp += rhs;
}

polynomial operator*(const polynomial &p, const polynomial::term &rt)
{
    polynomial tmp = p;
    return tmp *= rt;
}

polynomial operator*(const polynomial &lhs, const polynomial &rhs)
{
    polynomial tmp = lhs;
    return tmp *= rhs;
}
