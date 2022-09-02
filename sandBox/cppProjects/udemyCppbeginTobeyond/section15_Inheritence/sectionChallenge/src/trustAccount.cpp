#include "trustAccount.h"

TrustAccount::TrustAccount (std::string name, double balance, double interest_rate)
    : SavingsAccount(name, balance, interest_rate), remaining_withdrawls {def_yearly_withrdawls} {

    }

bool TrustAccount::withdraw (double amount) {
    if ((balance-amount) >= 0 && remaining_withdrawls > 0) {
        remaining_withdrawls--;
        return Account::withdraw(amount);
    }
    else {
        return false;
    }
}    

std::ostream &operator<< (std::ostream &os, const TrustAccount &account) {
    os << "[ Trust Account: " << account.name << " : " << account.balance << " : " << account.interest_rate << " : " << account.remaining_withdrawls << " ]";
    return os;
}
