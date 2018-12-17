/*======================================================================
*        filename: Sales_item.h
*        author: rambogui
*        data: 2018-12-17 14:55:53
======================================================================*/

#ifndef SALES_ITEM_H_
#define SALES_ITEM_H_

#include <iostream>
#include <string>

class Sales_item
{
private:
    std::string isbn;
    double sale;
    long num;
public:
    Sales_item(const std::string &isbn = "null", 
        double sale = 0.0, long num = 0) :
        isbn(isbn), sale(sale), num(num) {}
    std::string Isbn() const { return isbn; }
    Sales_item& operator= (const Sales_item &si);
    Sales_item operator+ (const Sales_item &si);
    Sales_item& operator+= (const Sales_item &si);

    friend std::ostream& operator<< (std::ostream &os, const Sales_item &si);
    friend std::istream& operator>> (std::istream &is, Sales_item &si);
};

Sales_item& Sales_item::operator= (const Sales_item &si)
{
    if (this == &si) return *this;

    isbn = si.isbn;
    sale = si.sale;
    num = si.num;
}

Sales_item Sales_item::operator+ (const Sales_item &si)
{
    if (isbn != si.isbn) return Sales_item();

    return Sales_item(isbn, (sale*num+si.sale*si.num)/(num+si.num),
                        num+si.num);
}

Sales_item& Sales_item::operator+= (const Sales_item &si)
{
    if (isbn == si.isbn) {
        sale = (sale*num + si.sale*si.num)/(num+si.num);
        num += si.num;
    }

    return *this;
}

std::ostream& operator<< (std::ostream &os, const Sales_item &si)
{
    os << si.isbn << ' ' << si.num << ' ' << si.sale*si.num << ' ' << si.sale;
    return os;
}

std::istream& operator>> (std::istream &is, Sales_item &si)
{
    is >> si.isbn >> si.num >> si.sale;
}

#endif
