/*======================================================================
*        filename: Account.cpp
*        author: rambogui
*        data: 2018-12-25 13:32:52
======================================================================*/

#include <iostream>
#include <string>

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate;}
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

double Account::interestRate = Account::initRate();

void Account::rate(double newRate)
{
    interestRate = newRate;
}
