/*======================================================================
*        filename: stack.h
*        author: rambogui
*        data: 2018-12-06 13:41:34
======================================================================*/

#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
};

#endif
