/*======================================================================
*        filename: sqtack.h
*        author: rambogui
*        data: 2019-01-17 13:47:00
======================================================================*/

#include <iostream>
#include <initializer_list>
#include <string>

class elem_type {
public:
    elem_type(int e = 0) : elem(e) { }  

friend std::ostream& operator<<(std::ostream &os, const elem_type &e);

private:
    int elem;
};

std::ostream& operator<<(std::ostream &os, const elem_type &e);

template <typename T>
class stack {
public:
    typedef T value_type;
    typedef int stack_size;
    const static stack_size STACK_INIT_SIZE = 10;
    const static stack_size STACKINCREMENT = 2;

    stack() : base(new T[STACKINCREMENT]), top(base), 
        staticsize(STACKINCREMENT) { }
    stack(const stack &s);
    ~stack();
    stack& operator=(const stack &s);

    void clear() { top = base;}
    bool empty() const { return top == base; }
    stack_size length() const { return top-base; }

    bool get_top(T &e);
    void push(const T &e);
    bool pop(T &e);
    void reset();

private:
    T *base;
    T *top;
    stack_size staticsize;
    void mem_incre();
};

template <typename T>
void stack<T>::mem_incre()
{
    T *tmp_base = new T[staticsize+STACKINCREMENT];
    T *tmp = base;
    int i;
    for (i = 0; tmp != top; ++tmp, ++i)
        tmp_base[i] = *tmp;
    top = tmp_base+i;
    delete[] base;
    base = tmp_base;
    staticsize += STACKINCREMENT;
}

template <typename T>
stack<T>::stack(const stack &s) : base(new T[s.staticsize]), top(base),
    staticsize(s.staticsize)
{
    T* tmp = s.base; 
    while (tmp != s.top) {
        push(*tmp);
        tmp++;
    }
}

template <typename T>
stack<T>::~stack()
{
    delete [] base;
}

template <typename T>
stack<T>& stack<T>::operator=(const stack &s)
{
    if (this != &s) {
        staticsize = s.staticsize;
        delete [] base;
        base = new T[staticsize];
        top = base;

        T* tmp = s.base;
        while (tmp != s.top) {
            push(*tmp);
            tmp++;
        }
    }
    return *this;
}

template <typename T>
bool stack<T>::get_top(T &e)
{
    if (top == base)
        return false;
    e = base[top-base-1];
    return true;
}

template <typename T>
void stack<T>::push(const T &e)
{
    if ((top-base+1) == staticsize)
        mem_incre();

    base[(top++)-base] = e;
}

template <typename T>
bool stack<T>::pop(T &e)
{
    if (top == base)
        return false;
    e = base[(--top)-base];
    return true;
}

template <typename T>
void stack<T>::reset()
{
    top = base;
}

template <typename T>
std::ostream& operator<<(std::ostream &os, stack<T> s)
{
    T tmp; 
    while (!s.empty()){
        s.pop(tmp);
        os << tmp << ' ';
    }
    return os;
}
