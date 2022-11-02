#pragma once
#include "i_printable.h"
#include <iostream>

class Account: public iPrintable {
    private:
    static constexpr const char *def_name = "Unamed Account";
    static constexpr double def_balance = 0;

    protected:
    std::string name;
    double balance;

    public:
    Account (std::string name = def_name, double balance = def_balance);
    virtual bool deposit (double amount);
    virtual bool withdraw (double amount);
    virtual void print (std::ostream &os) const override {};

    virtual ~Account () {};

};