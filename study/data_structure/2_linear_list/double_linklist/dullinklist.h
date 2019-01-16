/*======================================================================
*        filename: dullinklist.h
*        author: rambogui
*        data: 2019-01-16 15:52:55
======================================================================*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

class dullinklist {
public:
    typedef int dullinklist_size;

    class elem_type {
    public:
        elem_type(int e = 0) : elem(e) { }

    friend std::ostream& operator<<(std::ostream &os, const elem_type &e);

    private:
        int elem;
    };

    class dul_node {
    friend class dullinklist;
    public:
        dul_node(const elem_type &e = elem_type()) :
            data(e), prior(this), next(this) { }
        const elem_type& get_data() const { return data; }
        const dul_node *const get_prior() const { return prior; }
        const dul_node *const get_next() const { return next; }
    private:
        elem_type data;
        dul_node *prior;
        dul_node *next;
    };

    dullinklist() : head(new dul_node), len(0) { }
    dullinklist(std::initializer_list<elem_type> il);
    dullinklist(const dullinklist &dll);
    ~dullinklist();
    dullinklist& operator=(const dullinklist &dll);

    dullinklist_size length() const { return len; }
    void push_back(const elem_type &e);
    void push_back(std::initializer_list<elem_type> il);

friend std::ostream& operator<<(std::ostream &os, const dullinklist &dll);

private:
    dul_node *head;
    dullinklist_size len;
    void reset();
};


std::ostream& operator<<(std::ostream &os, const dullinklist::elem_type &e);
std::ostream& operator<<(std::ostream &os, const dullinklist &dll);
