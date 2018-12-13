/*======================================================================
*        filename: stock00.cpp
*        author: rambogui
*        data: 2018-12-04 09:49:43
======================================================================*/

#include <iostream>
#include "stock00.h"

void Stock::acquire(const std::string &co, long n, double pr)
{
    company = co;
    if (n < 0) {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    } else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{
    if (num < 0) {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0) {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    } else if (num > shares) {
        cout << "Your can't sell more than you have! "
             << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    std::cout << "Company: " << company
              << " Shares: " << shares << '\n'
              << " Share Price: $" << share_val
              << " Total Worth: $" << total_val << '\n';
}

#if 0
Stock::Stock(const std::string &company, long shares, double share_val)
{
    this->company = company;
    if (shares < 0) {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        this->shares = 0;
    } else
        this->shares = shares;
    this->share_val = share_val;
    set_tot();
}
#else
Stock::Stock(const std::string &company, long shares, double share_val)
{
    company = company;
    if (shares < 0) {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    } else
        shares = shares;
    share_val = share_val;
    set_tot();
}
#endif
