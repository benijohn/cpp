#include "savingsAccount.h"

Savings::Savings (std::string name, double balance, double interest_rate) 
    : Account {name, balance}, interest_rate {interest_rate} {

    }

bool Savings::deposit (double amount) {
    amount += amount*(interest_rate/100);
    return Account::deposit(amount);
} 

bool Savings::withdraw (double amount) {
    return Account::withdraw(amount);
}

void Savings::print (std::ostream &os) const {
    os << "[ Savings Account: " << name << ", Balance: " << balance << ", Interest Rate: " << interest_rate << " ]";
}