#pragma once 

#include "account.h"

class SavingsAccount : public Account {
    public:
    // attributes
    double interest_rate;
    // methods
    void deposit (double amount);
    void deposit ();
    void withdraw (double amount);
    void withdraw ();

    // constructors/destructor
    SavingsAccount ();
    ~SavingsAccount ();
};