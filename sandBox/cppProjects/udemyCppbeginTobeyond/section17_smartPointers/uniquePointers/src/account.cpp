#include "account.h"
Account::Account (std::string name, double balance)
    : name {name}, balance {balance} {

}

bool Account::withdraw (double amount) {
    if (balance - amount > 0) {
        balance -= amount;
        return true;
    }
    else {
        return false;
    }
}

bool Account::deposit (double amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    }
    else {
        return false;
    }
}