/*======================================================================
*        filename: stock20.h
*        author: rambogui
*        data: 2018-12-06 10:40:12
======================================================================*/

#ifndef STOCK20_H_
#define STOCK20_H_

#include <string>

class Stock
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = share_val * shares; }
public:
    Stock();
    Stock(const std::string &co, long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    const Stock& topval(const Stock& s) const;
};

#endif
