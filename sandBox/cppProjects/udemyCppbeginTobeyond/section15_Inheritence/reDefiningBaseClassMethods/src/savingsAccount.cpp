#include "savingsAccount.hpp"


SavingsAccount::SavingsAccount (double balance, double interest_rate) 
    : Account {balance + (balance*interest_rate/100)}, interest_rate {interest_rate} {

    }

SavingsAccount::SavingsAccount ()
    : SavingsAccount {0.0, 0.0} {

    }    

void SavingsAccount::deposit (double amount) {
    amount = amount + (amount*interest_rate/100);
    Account::deposit (amount);
}

std::ostream &operator<< (std::ostream &out, const SavingsAccount &account) {
    out << "Savings account balance: " << account.balance << " Interest rate: " << account.interest_rate;
    return out;
}
