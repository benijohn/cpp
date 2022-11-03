#pragma once 
#include "savingsAccount.h"

class TrustAccount: public SavingsAccount {
    friend std::ostream &operator<< (std::ostream &os, const TrustAccount &account);

    private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_interest_rate = 0.0;
    static constexpr int def_yearly_withrdawls = 3;

    protected:
    int remaining_withdrawls;

    public:
    TrustAccount (std::string name = def_name, double balance = def_balance, double interest_rate = def_interest_rate);
    bool withdraw (double amount);
    int get_remaining_withdrawls () const;
};