/*======================================================================
*        filename: slinklist.h
*        author: rambogui
*        data: 2019-01-16 08:16:19
======================================================================*/

#include <iostream>
#include <initializer_list>
#include <string>

class slinklist {
public:
    typedef int slinklist_size;
    const static unsigned MAXSIZE = 10;
    const static unsigned INCREMENT = 2;
    class elemtype {
        friend class slinklist;
        public:
            elemtype(int e = 0) : elem(e) { }
            bool operator==(const elemtype &rhs) const;
        friend std::ostream& operator<<(std::ostream& os, const elemtype &e);
        private:
            int elem;
    };
    class component {
        friend class slinklist;
        public:
            component(const elemtype &e = elemtype(), int c = 0) :
                data(e), cur(c) { } 
        friend std::ostream& operator<<(std::ostream& os, const slinklist &sll);
        friend std::ostream& operator<<(std::ostream& os, const component &c);
        private:
            elemtype data;
            slinklist_size cur;
    };

    slinklist();
    slinklist(std::initializer_list<elemtype>);
    slinklist(const slinklist &);
    ~slinklist();
    slinklist& operator=(const slinklist &);

    bool empty() const { return leng == 0; }
    slinklist_size length() const { return leng; }
    slinklist_size total_length() const { return llsize; }
    bool reset();
    void insert(slinklist_size i, const elemtype &e);
    void delelem(slinklist_size i, elemtype &e);
    void push_back(const elemtype &e);
    void push_back(std::initializer_list<elemtype> il);
    slinklist_size locate_elem(const elemtype &e,
        bool (*cmp)(const elemtype &lhs, const elemtype &rhs));
    const component *get_mem() const;
    
    friend std::ostream& operator<<(std::ostream& os, const slinklist &sll);

private:
    component *pslinklist; 
    slinklist_size llsize;

    slinklist_size head;
    slinklist_size tail;
    slinklist_size leng;
    void init(slinklist_size size);
    void mem_incre();
    void check(slinklist_size i, const char *s);
};

bool compare(const slinklist::elemtype &lhs, const slinklist::elemtype &rhs);
std::ostream& operator<<(std::ostream &os, const slinklist::elemtype &e);
std::ostream& operator<<(std::ostream &os, const slinklist::component &c);
std::ostream& operator<<(std::ostream &os, const slinklist &sll);
