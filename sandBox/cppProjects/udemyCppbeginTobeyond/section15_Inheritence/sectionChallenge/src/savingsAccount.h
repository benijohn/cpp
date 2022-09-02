#pragma once
#include "account.h"

class SavingsAccount: public Account {
    friend std::ostream &operator<< (std::ostream &os, const SavingsAccount &account);

    private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_interest = 0.0;

    protected:
    double interest_rate;

    public:
    SavingsAccount (std::string name = def_name, double balance = def_balance, double interest_rate = def_interest);
    bool deposit (double amount);

};