/*======================================================================
*        filename: dullinklist.cpp
*        author: rambogui
*        data: 2019-01-16 15:52:55
======================================================================*/

#include "dullinklist.h"

void dullinklist::reset()
{
    dul_node *tmp = head->next;
    while (tmp != head) {
        tmp = tmp->next;
        delete tmp->prior;
    }
}

dullinklist::dullinklist(std::initializer_list<elem_type> il) : 
    head(new dul_node), len(0)
{
    for (std::initializer_list<elem_type>::iterator beg = il.begin();
        beg != il.end(); ++beg)
        push_back(*beg);
}

dullinklist::dullinklist(const dullinklist &dll) : head(new dul_node), len(0)
{
    for (dul_node *tmp = dll.head->next; 
        tmp != dll.head; tmp = tmp->next)
        push_back(tmp->data);
}

dullinklist::~dullinklist()
{
    reset();
    delete head;
}

dullinklist& dullinklist::operator=(const dullinklist &dll)
{
    if (this != &dll) {
        reset();
        for (dul_node *tmp = dll.head->next;
            tmp != dll.head; tmp = tmp->next)
            push_back(tmp->data);
    }
    return *this;
}
    
void dullinklist::push_back(const elem_type &e)
{
    dul_node* tmp = new dul_node(e);
    tmp->prior = head->prior;
    tmp->next = head;

    head->prior->next = tmp;
    head->prior = tmp;
    
    ++len;
}

void dullinklist::push_back(std::initializer_list<elem_type> il)
{
    for (std::initializer_list<elem_type>::iterator beg = il.begin();
        beg != il.end(); ++beg)
        push_back(*beg);
}

std::ostream& operator<<(std::ostream &os, const dullinklist::elem_type &e)
{
    os << e.elem;
    return os;
}

std::ostream& operator<<(std::ostream &os, const dullinklist &dll)
{
    const dullinklist::dul_node *tmp = dll.head->get_next();
    while (tmp != dll.head) {
        os << tmp->get_data() << ' ';
        tmp = tmp->get_next();
    }
    return os;
}
