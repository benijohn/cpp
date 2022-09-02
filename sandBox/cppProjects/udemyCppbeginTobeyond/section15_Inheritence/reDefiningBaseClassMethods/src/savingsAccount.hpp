#pragma once 
#include "account.hpp"

class SavingsAccount: public Account {
    friend std::ostream &operator<< (std::ostream &out, const SavingsAccount &account);

protected:
    double interest_rate;

public:
    SavingsAccount ();
    SavingsAccount (double balance, double interest_rate);

    void deposit (double amount);
    //withdraw is inherited       
};