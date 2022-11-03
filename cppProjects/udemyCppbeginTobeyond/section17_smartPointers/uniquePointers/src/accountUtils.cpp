#include "accountUtils.h"

// Standard account utils
void print (const std::vector<Account *> &accounts) {
    std::cout << "====List of Accounts===============" << std::endl;
    for (const auto acc: accounts) {
        std::cout << *acc << std::endl;
    }
}
void deposit (std::vector<Account *> &accounts, double amount) {
    for (auto acc: accounts) {
        if (acc->deposit(amount)) {
            std::cout << "Successfully deposited $" << amount << " to account: " << *acc << std::endl;
        }
        else {
            std::cout << "Deposit failed for account: " << acc << std::endl;
        }
    }
}
void withdraw (std::vector<Account *> &accounts, double amount) {
    for (auto acc: accounts) {
        if (acc->withdraw(amount)) {
            std::cout << "Successfully withdrew $" << amount << " from account: " << *acc << std::endl;
        } 
        else {
            std::cout << "Withdraw failed for account: " << acc << std::endl;
        }
    }
}

