#include "savingsAccount.h"

SavingsAccount::SavingsAccount (std::string name, double balance, double interest_rate) 
    : Account(name, balance), interest_rate {interest_rate} {

    }

bool SavingsAccount::deposit (double amount) {
    if (amount > 0) {
        amount += amount*(interest_rate/100);
        return Account::deposit(amount);
    }
    else {
        return false;
    }
} 

std::ostream &operator<< (std::ostream &os, const SavingsAccount &account) {
    os << "[ Savings Account: " << account.name << " : " << account.balance << " : " << account.interest_rate << "% ]";
    return os;
}