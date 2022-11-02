#include "checkingAccount.h"

CheckingAccount::CheckingAccount (std::string name, double balance) 
    : Account (name, balance) {

    }

bool CheckingAccount::withdraw (double amount) {
    if (balance - (amount + def_withdrawel_fee) > 0) {
        amount += def_withdrawel_fee;
        return Account::withdraw(amount);
    }
    else {
        return false;
    }
}   

std::ostream &operator<< (std::ostream &os, const CheckingAccount &account) {
    os << "[ Checking Account: " << account.name << " : " << account.balance << " : " << account.def_withdrawel_fee << " ]";
    return os;
}