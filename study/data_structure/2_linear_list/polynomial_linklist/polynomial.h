/*======================================================================
*        filename: polynomial.h
*        author: rambogui
*        data: 2019-01-17 08:22:03
======================================================================*/

#include <iostream>
#include <string>
#include <initializer_list>
#include <stdexcept>

class polynomial {
public:
    class term {
    public:
        term(float c = 0, int e = 0) : coef(c), 
            expn(e), next(nullptr) { }
        float get_coef() const { return coef; }
        int get_expn() const { return expn; }
        const term* get_next() const { return next; }
    
    friend std::ostream& operator<<(std::ostream& os, const term &t);
    friend class polynomial;

    private:
        float coef;
        int expn;
        term *next;
    };

    polynomial() : head(new term()) { }
    polynomial(std::initializer_list<term> il);
    polynomial(const polynomial &p);
    ~polynomial();
    polynomial& operator=(const polynomial &p);
    polynomial& operator+=(const polynomial &p);
    polynomial& operator*=(const term &t);
    polynomial& operator*=(const polynomial &p);

    void insert(const term &t);

friend std::ostream& operator<<(std::ostream& os, const polynomial &p);
friend polynomial operator+(const polynomial &lhs, const polynomial &rhs);
friend polynomial operator*(const polynomial &p, const term &rt);
friend polynomial operator*(const polynomial &lhs, const polynomial &rhs);

private:
    term *head;
    void reset();
};

std::ostream& operator<<(std::ostream& os, const polynomial::term &t);
std::ostream& operator<<(std::ostream& os, const polynomial &p);
polynomial operator+(const polynomial &lhs, const polynomial &rhs);
polynomial operator*(const polynomial &p, const polynomial::term &rt);
polynomial operator*(const polynomial &lhs, const polynomial &rhs);
