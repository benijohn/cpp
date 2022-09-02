#include "account.h"
#include <iostream>

Account::Account () 
    : balance {0}, name{"Acccount Name"}{

}

Account::~Account () {

}

void Account::deposit (double amount) {
    std::cout << "Account deposit called with value: " << amount << std::endl;
}

void Account::deposit () {
    std::cout << "Account deposit called with no value. No money was deposited" << std::endl;
}

void Account::withdraw (double amount) {
    std::cout << "Account withdraw called with value: " << amount << std::endl;
}

void Account::withdraw() {
    std::cout << "Account withdraw called with no value. No money was withdrawn." << std::endl;
}