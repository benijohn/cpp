#include "trustAccount.h"

Trust::Trust (std::string name, double balance, double interest_rate)
    : Savings {name, balance, interest_rate}, remaining_withdrawls {def_yearly_withrdawls} {

    }

bool Trust::withdraw (double amount) {
    if ((balance*0.2 >= amount) && remaining_withdrawls > 0) {
        remaining_withdrawls--;
        return Account::withdraw(amount);
    }
    else {
        return false;
    }
}    

bool Trust::deposit (double amount) {
    if (amount > large_deposit_threshhold) {
        amount += large_deposit_bonus;
    }
    return Account::deposit(amount);
}

void Trust::print (std::ostream &os) const {
    os << "[ Trust Account: " << name << ", Balance: " << balance << ", Interest Rate: " << interest_rate << ", Remaining Wihtdrawls: " << remaining_withdrawls << " ]";
}
