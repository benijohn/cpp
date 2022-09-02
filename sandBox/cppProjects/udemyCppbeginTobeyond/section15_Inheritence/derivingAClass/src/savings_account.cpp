#include "savings_account.h"
#include <iostream>

SavingsAccount::SavingsAccount () 
    : interest_rate {3.0} {

}

SavingsAccount::~SavingsAccount () {

}

void SavingsAccount::deposit (double amount) {
    std::cout << "SavingsAccount deposit called with value: " << amount << std::endl;
}

void SavingsAccount::deposit () {
    std::cout << "SavingsAccount deposit called with no value. No money was deposited" << std::endl;
}

void SavingsAccount::withdraw (double amount) {
    std::cout << "SavingsAccount withdraw called with value: " << amount << std::endl;
}

void SavingsAccount::withdraw() {
    std::cout << "SavingsAccount withdraw called with no value. No money was withdrawn." << std::endl;
}