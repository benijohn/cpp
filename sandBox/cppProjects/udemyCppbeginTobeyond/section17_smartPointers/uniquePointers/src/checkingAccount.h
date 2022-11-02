#pragma once
#include "account.h"

class Checking: public Account {
    private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 500.0;
    static constexpr double def_withdrawel_fee = 2.25;

    public:
    Checking (std::string name = def_name, double balance = def_balance);
    virtual bool withdraw (double amount) override;
    virtual bool deposit (double amount) override;
    virtual void print (std::ostream &os) const override;

    virtual ~Checking () {};

};