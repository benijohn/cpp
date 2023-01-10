#include "checkingAccount.h"

Checking::Checking (std::string name, double balance) 
    : Account {name, balance} {

    }

bool Checking::withdraw (double amount) {
    amount += def_withdrawel_fee;
    return Account::withdraw (amount);
}  

bool Checking::deposit (double amount) {
    return Account::deposit (amount);
}

void Checking::print (std::ostream &os) const {
    os << "[ Checking Account: " << name << ", Balance: " << balance << " ]";
}

