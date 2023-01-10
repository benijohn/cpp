#pragma once
#include "account.h"

class Savings: public Account {
    private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 1000.0;
    static constexpr double def_interest = 3.0;

    protected:
    // std::string name;
    // double balance;
    double interest_rate;

    public:
    Savings (std::string name = def_name, double balance = def_balance, double interest_rate = def_interest);
    virtual bool deposit (double amount) override;
    virtual bool withdraw (double amount ) override;
    virtual void print (std::ostream &os) const override;

    virtual ~Savings () {};
};