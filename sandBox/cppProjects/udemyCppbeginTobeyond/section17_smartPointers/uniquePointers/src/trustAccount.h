#pragma once 
#include "savingsAccount.h"

class Trust: public Savings {
    private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 10000.0;
    static constexpr double def_interest_rate = 7.5;
    static constexpr int def_yearly_withrdawls = 3;
    static constexpr int large_deposit_bonus = 500;
    static constexpr int large_deposit_threshhold = 5000;

    protected:
    int remaining_withdrawls;

    public:
    Trust (std::string name = def_name, double balance = def_balance, double interest_rate = def_interest_rate);
    virtual bool withdraw (double amount) override;
    virtual bool deposit (double amount) override;
    virtual void print (std::ostream &os) const override;

    virtual ~Trust () {};
};